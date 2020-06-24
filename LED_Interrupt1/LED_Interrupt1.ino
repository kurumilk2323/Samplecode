/*
全点灯からボタンを押すと5秒後に5秒間LED激しく点灯させる。
スイッチ連打でも、はじめのスイッチが有効。
離したときに押されたと判断
*/
#define LEDpin1 2 // LED��ڑ�����GPIO�ԍ� //LEDピンのポート番号
#define LEDpin2 13 // LED��ڑ�����GPIO�ԍ�　//Red LEDのポート番号
#define SWpin1 0 // SW��ڑ�����GPIO�ԍ�　//LEDスイッチのポート番号
#define SWpin2 16 // SW��ڑ�����GPIO�ԍ�　//自作スイッチのポート番号

const int RED_PIN = 13;
const int YELLOW_PIN = 12;
const int BLUE_PIN = 14;
const int T =500;//����T[ms]
int SWdata;
int LedStatus = LOW;
int flg = 0;
int i=0;
int timer_end_flg=0;

void setup() 
{
  Serial.begin(115200);

  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT); //Red LEDのポート番号。下のレッドピンと被るが、妥協。
  pinMode(SWpin1, INPUT);
  pinMode(SWpin2, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  attachInterrupt( SWpin1, intFunc1, CHANGE); //監視ポート、割り込み処理関数、要因。 CHANGE: 状態変化時。
  attachInterrupt( SWpin2, intFunc2, RISING); //FALLING: HIGH -> LOWで割り込み処理。つまり離したとき、RISINGは逆。ただ、小野のは論理的に逆な回路なので、RISINGを使用。
  
  digitalWrite(LEDpin1, LedStatus);
}

void timer(int x){
  Serial.println("in func timer");
  delay(x);
}

void loop()
{
  if(LedStatus==HIGH){ //割り込みが発生した場合。
    timer(5000); //自作のタイマー関数
    Serial.print("Timer end, process start.\n");      
  }else{
    //全点灯させる
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(RED_PIN, HIGH);  
  }
}

void intFunc1() //基盤スイッチ割り込み関数。
{
  Serial.println("Intr SW1");

  SWdata = digitalRead(SWpin1); 
  if(SWdata == 0){
    digitalWrite(LEDpin1, HIGH);
  } 
  else{
    digitalWrite(LEDpin1, LOW);
  }
}

void intFunc2() //自作スイッチについての割り込み関数
{
    Serial.println("Intr SW2");
  
    if(LedStatus == LOW) {
      LedStatus = HIGH; //ボタンが押されたときのフラグ処理。
    }
    else {
      LedStatus = LOW;
    }
}
