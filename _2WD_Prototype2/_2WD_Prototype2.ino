
//2WD Prototype
//By JORGE
//Arduino uno, DFrobot 2drives L298, 2 dc 6v 0.4A

int E2 = 5; //Pwm motor 2---5
int M2 = 4; //Motor 2 con sensor---4
int E1 = 6; //Pwm motor 1---6                      
int M1 = 7; //Motor 1 sin sensor---7                        
int X = A0; // Eje x joystick
int Y = A1; // Eje y joystick
int R = A5; // Entrada encoder
int val = 0;
int vel1 = 0;
int vel2 = 0;
int dir = 0;
int gir = 0;
int LED = 13;
void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(LED, OUTPUT);
    pinMode(X, INPUT);   //Entrada eje X joystick
    pinMode(Y, INPUT);   //Entrada eje Y joystick
    pinMode(R, INPUT);   //Entrada encoder
} 
void loop()
{
  int val = analogRead(X);
  int gir = analogRead(Y);
  dir = map(val, 0, 1023, 170, 750);
  vel1 = map(val, 400, 750, 0, 255);
  vel2 = map(val, 430, 170, 0, 255);
  gir = map(gir, 0, 1023, -255, 255);
  if(dir > 500)
  {
   
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, vel1);
    analogWrite(E2, vel1);
    digitalWrite(LED, LOW);
    delay(10);
  }
   if(dir < 400)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, vel2);
    analogWrite(E2, vel2);
    digitalWrite(LED, LOW);
    delay(20);
  }
  /*if(gir > 400)
  {
    analogWrite(E1, gir);
  }
  if(gir < 400)
  {  
    analogWrite(E2, gir);
  }*/ 
  else
  {
    analogWrite(E1, LOW);
    analogWrite(E2, LOW);
    digitalWrite(LED, HIGH);
  }

}
  
