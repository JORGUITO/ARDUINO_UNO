
//2WD Prototype3
//By JORGE
//Arduino uno, DFrobot 2drives L298, 2 dc 6v 0.4A

int E2 = 5; //Pwm motor 2---pin5
int M2 = 4; //Motor 2 con sensor---pin4
int E1 = 6; //Pwm motor 1---pin6                      
int M1 = 7; //Motor 1 sin sensor---pin7                        
int movY = A0; // Eje x joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
int girX = A1; // Eje y joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
int R = A5; // Entrada encoder
int joyY = 0;
int joyX = 0;
int Y = 0;
int YY = 0;
int X = 0;
int XX = 0;
int LED = 13;
int intensidad = 3; 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int i = 0; 
int m = 0;
void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(LED, OUTPUT);  //Salida LED punto muerto
    pinMode(girX, INPUT);   //Entrada eje X joystick
    pinMode(movY, INPUT);   //Entrada eje Y joystick
    pinMode(R, INPUT);   //Entrada encoder
    Serial.begin(9600); 
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(intensidad, OUTPUT);
} 
void loop()
{
  i = analogRead(movY);
  m = map(i, 0, 512, 0, 255);
  Serial.print("LDR: ");  
  Serial.println(analogRead(i));  
  Serial.println("------");
  delay(1000); 
 
  analogWrite(intensidad, m);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255); 
  delay(100);

  analogWrite(intensidad, m);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 100);
  analogWrite(bluePin, 100); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0); 
  delay(100);
  
  analogWrite(intensidad, m);
  analogWrite(redPin,255);
  analogWrite(greenPin, 125);
  analogWrite(bluePin, 255); 
  delay(100);
  
  int Y = analogRead(movY); //Lectura eje Y
  int X = analogRead(girX); //Lectura eje X
  int XX = X - 511; //Centrado
  int YY = Y - 511; //Centrado
  int joyY = YY / 2; //Ajuste para salida analogica
  map(joyY, -255, 255, 0, 255);
  int joyX = XX / 2; //Ajuste para salida analogica
  map(joyX, -255, 255, 0, 255);
  E1 = min(E1, 255);
  E2 = min(E2, 255);
  E1 = max(E1, 0);
  E2 = max(E2, 0);
//Si el joystick va hacia delante...
  if(YY > 30)
  {
   if(XX > 0)
    {
    digitalWrite(M1, HIGH); //Motor 1 hacia adelante
    digitalWrite(M2, HIGH); //Motor 2 hacia adelante
    analogWrite(E1, joyY - joyX); //PWM M1 = incremento de Y + direccion de X
    analogWrite(E2, joyY); //PWM M2 = incremento de Y - direccion de X
    digitalWrite(LED, LOW); //LED punto muerto apagado
    delay(10);
    }
   if(XX < 0)
    {
    digitalWrite(M1, HIGH); //Motor 1 hacia adelante
    digitalWrite(M2, HIGH); //Motor 2 hacia adelante
    analogWrite(E1, joyY); //PWM M1 = incremento de Y + direccion de X
    analogWrite(E2, joyY + joyX); //PWM M2 = incremento de Y - direccion de X 
    digitalWrite(LED, LOW); //LED punto muerto apagado
    delay(10);
    } 
  }
  
//Si el joystick va hicia atras...   
  if(YY < -30)
  {
   if(XX > 0)
    {
     digitalWrite(M1, LOW); //
     digitalWrite(M2, LOW);
     analogWrite(E1, -(joyY) - joyX);
     analogWrite(E2, -(joyY));
     digitalWrite(LED, LOW);
     delay(20);
    }
   if(XX < 0)
    {
    digitalWrite(M1, LOW); //
    digitalWrite(M2, LOW);
    analogWrite(E1, -(joyY));
    analogWrite(E2, -(joyY) - joyX);
    digitalWrite(LED, LOW);
    delay(20);
    }
  }
  if(-30>= YY && YY <= 30)
  {
   if(XX < 0)
    {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, -(joyX));
    analogWrite(E2, -(joyX));
    digitalWrite(LED, LOW);
    delay(20);
    }
   if(XX < 0)
    {
     digitalWrite(M1, HIGH);
     digitalWrite(M2, LOW);
     analogWrite(E1, joyX);
     analogWrite(E2, joyX);
     digitalWrite(LED, LOW);
     delay(20);
    }
  }
  
  else
  {
    analogWrite(E1, LOW);
    analogWrite(E2, LOW);
    digitalWrite(LED, HIGH);
  }
}
