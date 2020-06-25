/*仕様
1. ボタンを押しているときに、Ton/Tのduty比で点灯する黄色ランプを作成する。
2. ボタンを押下したら、Tonをカウントアップしてduty比を上げる。
*/

const int RED_PIN = 13;
const int YELLOW_PIN = 12;
const int BLUE_PIN = 14;
const int PUSH_SW1 = 16;
const int T =20;//����T[ms]
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PUSH_SW1, INPUT);
  Serial.begin(115200);
}
int Ton = 1; //Duty比計算の分母部分
int flg = 0; //ボタン押下するためのフラグ
int flg_off = 0;
void loop() {
  int status;
  status = digitalRead(PUSH_SW1);
  if(status == LOW){
    Serial.print("ON");
    digitalWrite(YELLOW_PIN, HIGH);
    vTaskDelay((T)/10);
    digitalWrite(YELLOW_PIN, LOW);
    vTaskDelay((T)*(10-Ton)/10);
    flg=1; //ボタンを押したときのフラグを立てる。
  }else{ //ボタンを押していないときには、duty比 = 16 / 4で回す。
    flg_off=1; //離したときにフラグを立てる。
    Serial.print("OFF");
    digitalWrite(YELLOW_PIN, HIGH);
    vTaskDelay((T/5)*4);
    digitalWrite(YELLOW_PIN, LOW);
    vTaskDelay(T/5);
    flg=0; //離してもカウントアップされないようにする
  }
  if(flg==1 and flg_off==1){ //ボタンを押したときTonをカウントアップするフラグ条件
    Ton++;
    flg=0;
    flg_off=0;
    if(Ton>10){ //もしTonが10より大きいのであれば、0に初期化。10-Tonでマイナスになるのを防ぐため。
      Ton=0;
    }
  }
  Serial.print("Ton : ");
  Serial.println(Ton);
}
