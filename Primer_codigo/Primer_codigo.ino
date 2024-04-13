/*Fundacion Kinal
  Centro Eduacativo Tecnico Laboral Kinal
  Quimto perito
  Quinto electronica
  Codigo tecnico: EB5AM
  Curso: Taller electronica digital y reparacion de computadoras I
  Proyecto: Como leer un pin digital
  Dev: Eduardo Sebastian Orozco Colop
  Fecha 12 de abril
 */
    
// Directivas del preprocesador
    #define push_botton 2
    #define led 3
    
    void setup() {
    pinMode(push_botton, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
    Serial.println("Lectura de un pulsador");
  }

void loop() {
  bool estado_boton = digitalRead(push_botton);
  if (estado_boton == HIGH)
  {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}
