const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int buzzer = 9;
const int rele = 10;
const int E = 7;
const int segmentos[E] = {a, b, c, d, e, f, g};

const int numeros[10][E] = {
  /*9*/ {1, 1, 1, 1, 0, 1, 1},
  /*8*/ {1, 1, 1, 1, 1, 1, 1},
  /*7*/ {1, 1, 1, 0, 0, 0, 0},
  /*6*/ {1, 0, 1, 1, 1, 1, 1},
  /*5*/ {1, 0, 1, 1, 0, 1, 1},
  /*4*/ {0, 1, 1, 0, 0, 1, 1},
  /*3*/ {1, 1, 1, 1, 0, 0, 1},
  /*2*/ {1, 1, 0, 1, 1, 0, 1},
  /*1*/ {0, 1, 1, 0, 0, 0, 0},
  /*0*/ {1, 1, 1, 1, 1, 1, 0},    
};
const int APAGADO = LOW;

void setup() {
  for (int q=0; q<E; q++){
    pinMode(segmentos[q], OUTPUT);
    digitalWrite(segmentos[q], APAGADO); 
  }
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
  
  for (int q=0; q<10; q++){
    print(q);
    delay(1000);    
  }
  tone(buzzer, 250 , 500);
  
  digitalWrite(rele, LOW);
   
}

void print(int z){
  for (int q=0; q<E; q++){
    digitalWrite(segmentos[q], numeros [z][q]);
  }
}

void loop() {   
}
