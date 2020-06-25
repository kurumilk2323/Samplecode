/*仕様
1. 自然数nを定義
2. nを2で割って、あまりをbitに代入 i.e.6の場合、6/2=3...0, 3/2=1...1, 1/2=0...1:  5/2=2...1, 2/2=1...0, 1/2=0...1
3. 2を、nが0になるまで繰り返す。
4. nは0~7までにするために、n>=7になったらn=0にする。
 */

const int RED_PIN = 13;
const int YELLOW_PIN = 12;
const int BLUE_PIN = 14;
const int PUSH_SW1 = 16;
const int T =20;//

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PUSH_SW1, INPUT);
  Serial.begin(115200);
}

int n = 0; // counter 
int b[3]; // binaryを格納する配列
int i=0;
int num=0;
void loop() {
  
  int status;
  status = digitalRead(PUSH_SW1); //ボタンを押しているか、状態判定 I/O
  b[0]=b[1]=b[2]=0; // 配列の初期化
  if(status == LOW){ //回路より、スイッチを入れるとGNDに繋がるため、スイッチをオンでLOWになる。
    Serial.print("Count(decimal) : ");
    Serial.println(n);
    num = n; //
    Serial.print("ON\n");
    for (i = 0;num > 0; i++){ //0より大きくなるまで商を求めて次の割る対象へ。あまりを求めて代入していく。
      b[i] = num % 2; //あまりを代入
      num = num / 2; // 商を求めて次の割る対象へ。
    }
    Serial.print("\n");
    while (i > 0){
      Serial.println(b[--i]); //ビット列を出力
    }
    
    if(b[0]==1){ //ビット列で、0,1に応じて出力変更
      digitalWrite(BLUE_PIN, HIGH);
    }else{
      digitalWrite(BLUE_PIN, LOW);
    }
    if(b[1]==1){
      digitalWrite(YELLOW_PIN, HIGH);
    }else{
      digitalWrite(YELLOW_PIN, LOW);
    }
    if(b[2]==1){
      digitalWrite(RED_PIN, HIGH);
    }else{
      digitalWrite(RED_PIN, LOW);
    }
    vTaskDelay(1000);
    
    if(n<7){ //7より小さい場合にインクリメント
      n++; 
      }else{ //7より大きくなったら、0に戻る。
        b[0]=b[1]=b[2]=0;
        n=0;
    }
  }else{ //以下：ボタンを押していないとき、減っていく処理。
    Serial.print("Count(decimal) : ");
    Serial.println(n);
    num = n;
    Serial.print("OFF\n");
    for (i = 0;num > 0; i++){
      b[i] = num % 2;
      num = num / 2;
    }
    Serial.print("\n");
    while (i > 0){
      Serial.println(b[--i]);
    }
    
    if(b[0]==1){
      digitalWrite(BLUE_PIN, HIGH);
    }else{
      digitalWrite(BLUE_PIN, LOW);
    }
    if(b[1]==1){
      digitalWrite(YELLOW_PIN, HIGH);
    }else{
      digitalWrite(YELLOW_PIN, LOW);
    }
    if(b[2]==1){
      digitalWrite(RED_PIN, HIGH);
    }else{
      digitalWrite(RED_PIN, LOW);
    }
    vTaskDelay(1000);
    if(n>0){ //0より大きい時にはデクリメント
      n--;
    }else{ //0以下になったら7に戻る。
        b[0]=b[1]=b[2]=0;
        n=7;
    }    
  }
}
