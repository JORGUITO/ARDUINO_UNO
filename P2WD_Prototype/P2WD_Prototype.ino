
//2WD Prototype3
//By JORGE
//Arduino uno, DFrobot 2drives L298, 2 dc 6v 0.4A

int E2 = 5; //Pwm motor 2---pin5
int M2 = 4; //Motor 2 con sensor---pin4
int E1 = 6; //Pwm motor 1---pin6                      
int M1 = 7; //Motor 1 sin sensor---pin7                        
int movY = A0; // Eje x joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
int girX = A1; // Eje y joystick||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||777
unsigned int joyY = 0; // Absolutos para aceleracion
unsigned int joyX = 0; // Absolutos para aceleracion
int Y = 0; // variable para eje Y
int YY = 0; // variable para centrado de Y
int X = 0; // variable para eje X
int XX = 0; // variable para centrado de X
int LED = 12; //Led de punto muerto

void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(LED, OUTPUT);  //Salida LED punto muerto
    pinMode(girX, INPUT);   //Entrada eje X joystick
    pinMode(movY, INPUT);   //Entrada eje Y joystick
    Serial.begin(9600);    //Inicio monitor serial?? mas tarde!!!
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
  if(YY > 100) // Si eje Y es mayor que 100
  {
    if(XX < 200 && XX > -200) // y eje X entre 200 y -200
    {
     digitalWrite(M1, HIGH); //Motor 1 hacia adelante
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyY); //PWM M1
     analogWrite(E2, joyY); //PWM M2
     digitalWrite(LED, LOW); //LED punto muerto apagado
     delay(20); 
    }
   if(XX > 200) //y eje X es mayor que 200
    {
     digitalWrite(M1, HIGH); //Motor 1 hacia adelante
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyY - joyX/2); //PWM M1 = incremento de Y - direccion de X entre 2
     analogWrite(E2, joyY); //PWM M2 
     digitalWrite(LED, LOW); //LED punto muerto apagado
     delay(10);
    }
   if(XX < -200) //y eje X es menor que - 200
    {
     digitalWrite(M1, HIGH); //Motor 1 hacia adelante
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyY); //PWM M1 
     analogWrite(E2, joyY - joyX/2); //PWM M2 = incremento de Y - direccion de X entre 2 
     digitalWrite(LED, LOW); //LED punto muerto apagado
     delay(10);
    } 
  }
  
//Si el joystick va hacia atras...   
  if(YY < -100) // Si Eje Y es menor que -100
  {
    if(XX < 100 && XX > -100) //y eje X entre 100 y -100
    {
     digitalWrite(M1, LOW); //Motor 1 hacia atras
     digitalWrite(M2, LOW); //Motor 2 hacia atras
     analogWrite(E1, joyY); //PWM M1
     analogWrite(E2, joyY); //PWM M2
     digitalWrite(LED, LOW); //LED de punto muerto apagado
     delay(20);
    } 
   if(XX > 100) //y eje X es mayor que 100
    {
     digitalWrite(M1, LOW); //Motor 1 hacia atras
     digitalWrite(M2, LOW); //Motor 2 hacia atras
     analogWrite(E1, joyY); //PWM M1
     analogWrite(E2, joyY - joyX/2); //PWM M2 = incremento de Y - direccion de X entre 2
     digitalWrite(LED, LOW); //LED de punto muerto apagado
     delay(20);
    }
   if(XX < -100) //y eje X es menor que -100
    {
    digitalWrite(M1, LOW); //Motor 1 hacia atras
    digitalWrite(M2, LOW); //Motor 2 hacia atras
    analogWrite(E1, joyY - joyX/2); //PWM M1 = incremento de Y - direccion de X entre 2
    analogWrite(E2, joyY); //PWM M2
    digitalWrite(LED, LOW); //LED de punto muerto apagado
    delay(20);
    }
  }
  if(-100<= YY && YY <= 100) // Si eleje Y esta entre 100 y -100
  {
   if(XX < -100) //y el eje X es menor que -100
    {
    digitalWrite(M1, HIGH); //Motor 1 hacia adelante
    digitalWrite(M2, LOW); //Motor 2 hacia atras
    analogWrite(E1, joyX); //PWM M1
    analogWrite(E2, joyX); //PWM M2
    digitalWrite(LED, LOW); //LED de punto muerto apagado
    delay(20);
    }
   if(XX > 100) //y el eje X es mayor que 100
    {
     digitalWrite(M1, LOW); //Motor 1 hacia atras
     digitalWrite(M2, HIGH); //Motor 2 hacia adelante
     analogWrite(E1, joyX); //PWM M1
     analogWrite(E2, joyX); //PWM M2
     digitalWrite(LED, LOW); //LED de punto muerto apagado
     delay(20);
    }
  }
  
  else // para lo demas
  {
    analogWrite(E1, LOW); //PWM M1 en LOW para apagado
    analogWrite(E2, LOW); //PWM M2 en LOW para apagado
    digitalWrite(LED, HIGH); //LED de punto muerto encendido
  }
}
