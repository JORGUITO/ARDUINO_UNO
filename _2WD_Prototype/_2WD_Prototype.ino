

//2WD Prototype
//By JORGE
//Arduino uno, DFrobot 2drives L298, 2 dc 6v 0.4A

int E2 = 5; //Pwm motor 2
int M2 = 4; //Motor 2 con sensor
int E1 = 6; //Pwm motor 1                      
int M1 = 7; //Motor 1 sin sensor                        
int X = A0; // Eje x joystick
int Y = A1; // Eje y joystick
int R = A5; // Entrada encoder
int val = 0;
int velo = (520 + val);
int velu = (-1 * val);
int LED = 13;
void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(X, INPUT);   //Entrada eje X joystick
    pinMode(Y, INPUT);   //Entrada eje Y joystick
    pinMode(R, INPUT);   //Entrada encoder
} 
 
void loop()
{
//  Serial.begin(9600);
//  Serial.print("X"); Serial.println(A0); 
//  delay(1000);
  int val = analogRead(X);
  int dir = analogRead(Y);
  val = map(val, 200, 800, -80, 255);
  dir = map(dir, 200, 800, -80, 255);
//  val = constrain(val, -254, 254);
//  dir = constrain(dir, -80, 254);
  if(val > 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, val-0);
    analogWrite(E2, val-0);
    delay(20);
  }
  if(val < 0)
  {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, val+10);
    analogWrite(E2, val+10);
    delay(20);
  }
   if(dir > 0)
  {
    analogWrite(E2, val-50);
    delay(20);
  }
  if(dir < 0)
  {
    analogWrite(E1, val-50);
    delay(20);
  }
}
 /* if(Y > 0)
  {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    analogWrite(E1, 128);
    analogWrite(E2, vel);
    delay(20);
  }
  if(Y < 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, vel);
    analogWrite(E2, 128);
    delay(20);
  }
}
    
    









/*
void loop() 
{ 
  int valor;
  for(valor = 0 ; valor <= 255; valor+=5) 
  { 
    digitalWrite(M1,LOW);   
    digitalWrite(M2, LOW);       
    analogWrite(E1, valor);   //PWM Speed Control
    analogWrite(E2, valor);   //PWM Speed Control
    delay(100); 
  }  
}


*/
