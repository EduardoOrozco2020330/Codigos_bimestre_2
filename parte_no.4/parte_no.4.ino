int pinIncremento = 2;
int pinDecremento = 3;
 
int contador = 0;
 
void setup() {
  pinMode(pinIncremento, INPUT);
  pinMode(pinDecremento, INPUT);
  Serial.begin(9600);
  Serial.println(contador);
}
 
void loop() {
  if (digitalRead(pinIncremento) == HIGH) {
    delay(50);
    if (digitalRead(pinIncremento) == HIGH) {
      contador++;
      if (contador > 99) {
        contador = 0;
      }
      Serial.println(contador);
      delay(200);
    }
  }
 
  if (digitalRead(pinDecremento) == HIGH) {
    delay(50);
    if (digitalRead(pinDecremento) == HIGH) {
      contador--;
      if (contador < 0) {
        contador = 99;
      }
      Serial.println(contador);
      delay(200);
    }
  }
  }
