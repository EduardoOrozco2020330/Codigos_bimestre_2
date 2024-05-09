int no_c = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}
void loop() {
  for(int a=0; a<=9; a++){
  no_c = 500;
    if(digitalRead(2)==HIGH){
      no_c = 1000;}
    else if (digitalRead(3)==HIGH){
      no_c = 2000;}
    else if (digitalRead(4)==HIGH){
      no_c = 3000;}
    if (digitalRead(2)==HIGH && digitalRead(3)==HIGH && digitalRead(4)==HIGH){
      no_c = 500;}
    Serial.println(a);
    delay(no_c);
    }
  }
