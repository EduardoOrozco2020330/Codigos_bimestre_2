#include <LiquidCrystal.h>


//Definiciones de preprocesador
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5

//Constructor
LiquidCrystal LCD_1(RS, Enable, D4, D5, D6, D7); //Constructor que me permite usar la LCD



void setup()
{
  LCD_1.begin(16,2); //Objeto de una LCD de 16 columnas x 2 filas
  LCD_1.setCursor(0,0);
  LCD_1.print("Eduardo");
  LCD_1.setCursor(0,2);
  LCD_1.print("2020330");
}
void loop()
{
}
