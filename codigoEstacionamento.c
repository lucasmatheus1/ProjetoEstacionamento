#include <Servo.h>
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

// Variáveis
// Sensor 1
int ledVerde1 = 8;
int ledVermelho1 = 9;
#define trigPin1 10
#define echoPin1 11
// Sensor 2
int ledVerde2 = 12;
int ledVermelho2 = 13;
#define trigPin2 14
#define echoPin2 15
// Servo Entrada e Sensor Entrada
#define trigPin_servo_entrada 18
#define echoPin_servo_entrada 19
Servo servo_entrada; 
// Sensor 3
int ledVerde3 = 22;
int ledVermelho3 = 23;
#define trigPin3 24
#define echoPin3 25
// Sensor 4
int ledVerde4 = 26;
int ledVermelho4 = 27;
#define trigPin4 28
#define echoPin4 29
// Sensor 5
int ledVerde5 = 30;
int ledVermelho5 = 31;
#define trigPin5 32
#define echoPin5 33
// Servo saida e Sensor saida
#define trigPin_servo_saida 16
#define echoPin_servo_saida 17
Servo servo_saida;

//Pino 2 ao 7 para o lcd
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Ultrasonic ultrasonic(10,11);
Ultrasonic ultrasonic2(14,15);
Ultrasonic ultrasonic_servo_entrada(18,19);
Ultrasonic ultrasonic3(24,25);
Ultrasonic ultrasonic4(28,29);
Ultrasonic ultrasonic5(32,33);
Ultrasonic ultrasonic_servo_saida(16,17);

void setup() {
  // Entradas e Saídas
  Serial.begin(9600);
  lcd.begin(16, 2);
  //Sensor 1
  pinMode (echoPin1, INPUT); 
  pinMode (trigPin1, OUTPUT); 
  pinMode (ledVermelho1, OUTPUT);
  pinMode (ledVerde1, OUTPUT);
  // Sensor 2
  pinMode (echoPin2, INPUT); 
  pinMode (trigPin2, OUTPUT);
  pinMode (ledVermelho2, OUTPUT);
  pinMode (ledVerde2, OUTPUT);
  
  // Servo de entrada e Sensor de entrada
  pinMode (echoPin_servo_entrada, INPUT);
  pinMode (trigPin_servo_entrada, OUTPUT);
  servo_entrada.attach(20);
  // Sensor 3
  pinMode (echoPin3, INPUT); 
  pinMode (trigPin3, OUTPUT);
  pinMode (ledVermelho3, OUTPUT);
  pinMode (ledVerde3, OUTPUT);
  // Sensor 4
  pinMode (echoPin4, INPUT); 
  pinMode (trigPin4, OUTPUT);
  pinMode (ledVermelho4, OUTPUT);
  pinMode (ledVerde4, OUTPUT);
  // Sensor 5
  pinMode (echoPin5, INPUT); 
  pinMode (trigPin5, OUTPUT);
  pinMode (ledVermelho5, OUTPUT);
  pinMode (ledVerde5, OUTPUT);
  // Servo de saida e Sensor de saida
  pinMode (echoPin_servo_saida, INPUT);
  pinMode (trigPin_servo_saida, OUTPUT);
  servo_saida.attach(35);
}

void loop() {
  int vagaslivres = 5;   //Contador de vagas livres  
  int vagasocupadas = 0; //Contador de vagas ocupadas
    
  // Sensor e Servo de saida
  digitalWrite(trigPin_servo_saida, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_servo_saida, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin_servo_saida, LOW);
  //Distância servo entrada
  int distanciaCentimetros_servo_saida = (ultrasonic_servo_saida.Ranging(CM));
  Serial.print("Distância em Centimetros Servo Saida = ");
  Serial.println(distanciaCentimetros_servo_saida);
  if (distanciaCentimetros_servo_saida <= 10){
    servo_saida.write(0);
    delay(2500);
  }else{
    servo_saida.write(90);
  }
  
  //Sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin1, LOW);
  //Distância sensor 1
  int distanciaCentimetros = (ultrasonic.Ranging(CM));
  Serial.print("Distância em Centimetros = ");
  Serial.println(distanciaCentimetros);
  if (distanciaCentimetros <= 3){
     vagasocupadas += 1;
     vagaslivres -= 1; 
     digitalWrite(ledVermelho1, HIGH);
     digitalWrite(ledVerde1, LOW); 
  }else{
   digitalWrite(ledVermelho1, LOW);
   digitalWrite(ledVerde1, HIGH);
  }

  //Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);  
  //Distância sensor 2
  int distanciaCentimetros2 = (ultrasonic2.Ranging(CM));
  Serial.print("Distância em Centimetros2 = ");
  Serial.println(distanciaCentimetros2);
  //Leds do sensor 2
  if (distanciaCentimetros2 <= 5){
     vagasocupadas += 1;
     vagaslivres -= 1;    
     digitalWrite(ledVermelho2, HIGH);
     digitalWrite(ledVerde2, LOW);
  }else{
   digitalWrite(ledVermelho2, LOW);
   digitalWrite(ledVerde2, HIGH);
  }
  
  //Sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin3, LOW);  
  //Distância sensor 3
  int distanciaCentimetros3 = (ultrasonic3.Ranging(CM));
  Serial.print("Distância em Centimetros3 = ");
  Serial.println(distanciaCentimetros3);
  //Leds do sensor 3
  if (distanciaCentimetros3 <= 9){
     vagasocupadas += 1;
     vagaslivres -= 1;    
     digitalWrite(ledVermelho3, HIGH);
     digitalWrite(ledVerde3, LOW);
  }else{
   digitalWrite(ledVermelho3, LOW);
   digitalWrite(ledVerde3, HIGH);
  }
  
  //Sensor 4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin4, LOW);  
  //Distância sensor 2
  int distanciaCentimetros4 = (ultrasonic4.Ranging(CM));
  Serial.print("Distância em Centimetros4 = ");
  Serial.println(distanciaCentimetros4);
  //Leds do sensor 4
  if (distanciaCentimetros4 <= 6){
     vagasocupadas += 1;
     vagaslivres -= 1;    
     digitalWrite(ledVermelho4, HIGH);
     digitalWrite(ledVerde4, LOW);
  }else{
   digitalWrite(ledVermelho4, LOW);
   digitalWrite(ledVerde4, HIGH);
  }

  //Sensor 5
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin5, LOW);  
  //Distância sensor 5
  int distanciaCentimetros5 = (ultrasonic5.Ranging(CM));
  Serial.print("Distância em Centimetros5 = ");
  Serial.println(distanciaCentimetros5);
  //Leds do sensor 5
  if (distanciaCentimetros5 <= 5){
     vagasocupadas += 1;
     vagaslivres -= 1;    
     digitalWrite(ledVermelho5, HIGH);
     digitalWrite(ledVerde5, LOW);
  }else{
   digitalWrite(ledVermelho5, LOW);
   digitalWrite(ledVerde5, HIGH);
  }
  if (vagaslivres==0){
    Serial.print("oi");
    servo_entrada.write(0);
  }else{
    // Sensor e Servo de entrada
    digitalWrite(trigPin_servo_entrada, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin_servo_entrada, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin_servo_entrada, LOW);
    //Distância servo entrada
    int distanciaCentimetros_servo_entrada = (ultrasonic_servo_entrada.Ranging(CM));
    Serial.print("Distância em Centimetros Servo Entrada = ");
    Serial.println(distanciaCentimetros_servo_entrada);
    if (distanciaCentimetros_servo_entrada <= 10){
    servo_entrada.write(90);
    delay(2500);
    }else{
      servo_entrada.write(0);
    }  
  }

  //LCD
  //Posiciona o cursor na coluna 0, linha 0;
  lcd.setCursor(0, 0);
  lcd.print("Vagas Livres = ");
  lcd.print(vagaslivres);
  //Posiciona o cursor na coluna 0, linha 1;
  lcd.setCursor(0, 1);
  lcd.print("Vagas ocup. = ");
  lcd.print(vagasocupadas);
}
