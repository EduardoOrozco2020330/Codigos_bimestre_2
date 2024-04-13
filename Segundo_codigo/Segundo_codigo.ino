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
    #define LedVerde 4
    #define tiempo_espera 500

void setup()
{
  pinMode(LedVerde, OUTPUT);
  digitalWrite(LedVerde, LOW);
}

void loop()
{
  digitalWrite(LedVerde, HIGH);
  delay(tiempo_espera);
  digitalWrite(LedVerde, LOW);
  delay(tiempo_espera);
}
