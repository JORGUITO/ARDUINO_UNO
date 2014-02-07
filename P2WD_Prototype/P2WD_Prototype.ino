
//2WD Prototype3
//By JORGE
//Arduino uno, DFrobot 2drives L298, 2 dc 6v 0.4A

int E2 = 5; //Pwm motor 2---pin5
int M2 = 4; //Motor 2 con sensor---pin4
int E1 = 6; //Pwm motor 1---pin6                      
int M1 = 7; //Motor 1 sin sensor---pin7                        
int movY = A0; // Eje x joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
int girX = A1; // Eje y joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
unsigned int joyY = 0;
unsigned int joyX = 0;
int Y = 0;
int YY = 0;
int X = 0;
int XX = 0;
int LED = 12;

void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(LED, OUTPUT);  //Salida LED punto muerto
    pinMode(girX, INPUT);   //Entrada eje X joystick
    pinMode(movY, INPUT);   //Entrada eje Y joystick
    Serial.begin(9600); 
} 
void loop()
{
  
  int Y = analogRead(movY); //Lectura eje Y
  int X = analogRead(girX); //Lectura eje X
  int XX = X - 511; //Centrado
  int YY = Y - 511; //Centrado
  unsigned int joyY = YY / 2; //Ajuste para salida analogica
 // map(joyY, -255, 255, 0, 255);
  unsigned int joyX = XX / 2; //Ajuste para salida analogica
    joyY = min(joyY, 255);
    joyX = min(joyX, 255);
 // map(joyX, -255, 255, 0, 255);
 // E1 = min(E1, 255);
 // E2 = min(E2, 255);
 // E1 = max(E1, 0);
 // E2 = max(E2, 0);
//Si el joystick va hacia delante...
  if(YY > 100)
  {
    if(XX < 200 && XX > -200)
    {
     digitalWrite(M1, HIGH); //
     digitalWrite(M2, HIGH);
     analogWrite(E1, joyY);
     analogWrite(E2, joyY);
     digitalWrite(LED, LOW);
     delay(20); 
    }
   if(XX > 200)
    {
     digitalWrite(M1, HIGH); //Motor 1 hacia adelante
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyY - joyX/2); //PWM M1 = incremento de Y + direccion de X
     analogWrite(E2, joyY); //PWM M2 = incremento de Y - direccion de X
     digitalWrite(LED, LOW); //LED punto muerto apagado
     delay(10);
    }
   if(XX < -200)
    {
     digitalWrite(M1, HIGH); //Motor 1 hacia adelante
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyY); //PWM M1 = incremento de Y + direccion de X
     analogWrite(E2, joyY - joyX/2); //PWM M2 = incremento de Y - direccion de X 
     digitalWrite(LED, LOW); //LED punto muerto apagado
     delay(10);
    } 
  }
  
//Si el joystick va hacia atras...   
  if(YY < -100)
  {
    if(XX < 100 && XX > -100)
    {
     digitalWrite(M1, LOW); //
     digitalWrite(M2, LOW);
     analogWrite(E1, joyY);
     analogWrite(E2, joyY);
     digitalWrite(LED, LOW);
     delay(20);
    } 
   if(XX > 100)
    {
     digitalWrite(M1, LOW); //
     digitalWrite(M2, LOW);
     analogWrite(E1, joyY);
     analogWrite(E2, joyY - joyX/2);
     digitalWrite(LED, LOW);
     delay(20);
    }
   if(XX < -100)
    {
    digitalWrite(M1, LOW); //
    digitalWrite(M2, LOW);
    analogWrite(E1, joyY - joyX/2);
    analogWrite(E2, joyY);
    digitalWrite(LED, LOW);
    delay(20);
    }
  }
  if(-100<= YY && YY <= 100)
  {
   if(XX < -100)
    {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    analogWrite(E1, joyX);
    analogWrite(E2, joyX);
    digitalWrite(LED, LOW);
    delay(20);
    }
   if(XX > 100)
    {
     digitalWrite(M1, LOW);
     digitalWrite(M2, HIGH);
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
