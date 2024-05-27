#include <Wire.h>
#include <LiquidCrystal_I2C.h>  
#include <Servo.h>              
#include <Keypad.h>

#define direccion_lcd 0x20     
#define filas 2                
#define columnas 16

LiquidCrystal_I2C lcdEduardo(direccion_lcd, columnas, filas);

const int leds[] = {2, 3, 4, 5};
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

const int E = 7;
const int segmentos[E] = {a, b, c, d, e, f, g};

const int numeros[13][E] = {
  /*a*/ {1, 0, 0, 0, 0, 0, 0},
  /*f*/ {0, 0, 0, 0, 0, 1, 0},
  /*g*/ {0, 0, 0, 0, 0, 0, 1},
  /*c*/ {0, 0, 1, 0, 0, 0, 0},
  /*d*/ {0, 0, 0, 1, 0, 0, 0},
  /*e*/ {0, 0, 0, 0, 1, 0, 0},
  /*g*/ {0, 0, 0, 0, 0, 0, 1},
  /*b*/ {0, 1, 0, 0, 0, 0, 0},
  /*a*/ {1, 0, 0, 0, 0, 0, 0},
  };
const int APAGADO = LOW;
 
#define pin_Servo 9
#define filas_teclado 4        
#define columnas_teclado 4     
#define f1_teclado A0        
#define f2_teclado A1          
#define f3_teclado A2         
#define f4_teclado A3          
#define c1_teclado 10           
#define c2_teclado 11          
#define c3_teclado 12          
#define c4_teclado 13

Servo Servo_Eduardo;

char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};

Keypad teclado_io = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);

void setup() {
  Serial.begin(9600);
  lcdEduardo.init();
  lcdEduardo.backlight();
  lcdEduardo.setCursor(4,0);
  lcdEduardo.print("Eduardo");
  lcdEduardo.setCursor(0,1);
  lcdEduardo.print("Proyecto final");
  
  Servo_Eduardo.attach(pin_Servo);
  
  for (int S=0; S<sizeof(leds); S++){
    pinMode(leds[S], OUTPUT);
  }
  
    for (int q=0; q<E; q++){
    pinMode(segmentos[q], OUTPUT);
    digitalWrite(segmentos[q], APAGADO);
    }
}

void print(int z){
  for (int q=0; q<E; q++){
    digitalWrite(segmentos[q], numeros [z][q]);
  }
}

void loop() {
  char tecla = teclado_io.getKey();
  if(tecla){
    Serial.print("La tecla presionada es: ");   
    Serial.println(tecla);    
  }
  if(tecla == '1'){ // if de tecla 1
    Serial.println("contador 0 a 99");
    if (tecla == '1') {
      for (int contador = 0; contador <= 99; contador++) {
      Serial.println(contador); // Imprime el valor del contador en el monitor serie
      delay(100); 
      }
    }
  }
 
  if(tecla == '2'){ // if de tecla 1
    Serial.println("contador 0 a 99");
    if (tecla == '2') {
      for (int contador = 99; contador >= 0; contador--) {
      Serial.println(contador); // Imprime el valor del contador en el monitor serie
      delay(100); 
      }
    }
  }
  if(tecla == '3'){
   for (int S=0; S<sizeof(leds); S++){
    digitalWrite(leds[S], HIGH);
     delay(200);
    digitalWrite(leds[S], LOW); 
  }
    for (int S=sizeof(leds)-1; S>0; S--){
    digitalWrite(leds[S], HIGH);
     delay(200);
    digitalWrite(leds[S], LOW); 
  }
  }
  if(tecla == '4'){
    for (int q=0; q<10; q++){
    print(q);
    delay(900);
  }

  }
  if(tecla == '5'){ 
    Serial.println("inicia servo"); 
    Servo_Eduardo.write(0);
    delay(2000);
    Servo_Eduardo.write(180); 
    delay(2000);
     Servo_Eduardo.write(0);
  } 
}
