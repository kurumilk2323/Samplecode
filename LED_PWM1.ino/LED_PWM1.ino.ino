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

void loop() {
  int status;
  status = digitalRead(PUSH_SW1);
  if(status == HIGH){
    digitalWrite(YELLOW_PIN, HIGH);
    vTaskDelay((T/5)*4);
    digitalWrite(YELLOW_PIN, LOW);
    vTaskDelay(T/5);

  }else{
    digitalWrite(YELLOW_PIN, HIGH);
    vTaskDelay(T/2);
     digitalWrite(YELLOW_PIN, LOW);
    vTaskDelay(T/2);
  }
}
