const int RED_PIN = 13;
const int YELLOW_PIN = 12;
const int BLUE_PIN = 14;
const int PUSH_SW1 = 16;
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
    Serial.println("Signal color : BLUE");  
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    vTaskDelay(1000);
    Serial.println("Signal color : YELLOW");  
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    vTaskDelay(1000);
    Serial.println("Signal color : RED");  
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    vTaskDelay(1000);
}else{
    Serial.println("Signal color : RED");  
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    vTaskDelay(1000);
    Serial.println("Signal color : YELLOW");  
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    vTaskDelay(1000);
    Serial.println("Signal color : BLUE");  
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    vTaskDelay(1000);
}
}
