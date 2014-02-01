 /* Lee Jostick
  * ------------
  *
  * Lee dos entradas analógicas que se sopone que están conectadas a
  * un joystick fabricado con dos potenciómetros
  *
  * Enviamos tres bytes al ordenador: uno de cabecera y otros dos 
  * con datos como bytes con signo, esto tomará la forma:
  *		Jxy\r\n
  *
  * x e y son enteros y se mandan en ASCII 
  * 
  * http://www.0j0.org | http://arduino.berlios.de
  * copyleft 2005 DojoDave para DojoCorp
  */

 int ledPin = 13;
 int joyPin1 = 0;                 // potenciómetro conectado al pin analógico 0
 int joyPin2 = 1;                 // potenciómetro conectado al pin analógico 0
 int value1 = 0;                  // variable para leer el valor del pin analógico 0
 int value2 = 0;                  // variable para leer el valor del pin analógico 1

 void setup() {
  pinMode(ledPin, OUTPUT);              // inicializa el pin digital 13 como salida
  Serial.begin(9600);
 }

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void loop() {
  // lee el valor de la resistencia variable 
  value1 = analogRead(joyPin1);   
  // esta pequeña parada es necesaria entre lecturas de un pin analógico
  // de otra manera devolvería el mismo valor las dos veces
  delay(100);			  
  // lee el valor de la resistencia variable 
  value2 = analogRead(joyPin2);   

  digitalWrite(ledPin, HIGH);           
  delay(value1);
  digitalWrite(ledPin, LOW);
  delay(value2);
  Serial.print('J');
  Serial.println(treatValue(value1));
  Serial.print(treatValue(value2));
  Serial.println(10);
  Serial.print(13);
 }
