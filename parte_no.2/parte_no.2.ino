int ledPins[] = {2, 3, 4, 5, 6, 7}; // Pines para los LEDs
int funcion1 = 9; 
int funcion2 = 10; 
 
const int velo1 = 500; 
const int velo2 = velo1 / 2; 
 
void setup() {
    for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(funcion1, INPUT_PULLUP);
  pinMode(funcion2, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop() {
  bool switchState1 = digitalRead(funcion1);
  bool switchState2 = digitalRead(funcion2);
  if (!switchState1) {
    Serial.println("Secuencia - velocidad 1");
    runSequence(velo1);
  }
  // Si el segundo interruptor está presionado
  else if (!switchState2) {
    Serial.println("Secuencia - velocidad 2");
    runSequence(velo2);
  }
  // Si ninguno de los interruptores está presionado, no hacer nada
}
 
// Función para ejecutar la secuencia de luces
void runSequence(int speed) {
  for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    digitalWrite(ledPins[i], HIGH); // Encender el LED actual
    delay(speed); // Esperar según la velocidad
    digitalWrite(ledPins[i], LOW); // Apagar el LED actual
  }
  for (int i = sizeof(ledPins)/sizeof(ledPins[0]) - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH); // Encender el LED actual
    delay(speed); // Esperar según la velocidad
    digitalWrite(ledPins[i], LOW); // Apagar el LED actual
  }
}
