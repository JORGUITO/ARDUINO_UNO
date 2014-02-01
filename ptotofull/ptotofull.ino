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
int vel = 0;
int xmin = 200;                  // X minimum value
int xmax = 800;                  // X maximum value
int ymin = 200;                  // Y minimum value
int ymax = 800;                  // Y maximum value
int xzero = 0;                   // the first X value (don't touch the joystick at startup!)
int yzero = 0;                   // the first Y value
int segs = 20;                   // number of intervalls to consider par half direction
double zerohold = 4;             // number of intervalls to consider as "zero position" 
int velo = (12.75 * vel);
int velu = (-12.75 * vel);
int LED = 13;
void setup() 
{ 
    pinMode(M1, OUTPUT); //Salida para motor 1
    pinMode(M2, OUTPUT); //Salida para motor 2
    pinMode(X, INPUT);   //Entrada eje X joystick
    pinMode(Y, INPUT);   //Entrada eje Y joystick
    pinMode(R, INPUT);   //Entrada encoder
    yzero = analogRead(Y);  
    xzero = analogRead(X);
} 
 
void loop()
{
   // read the X value
  vel = analogRead(X);   
  // push limits
  if(vel<xmin) xmin=vel;
  else if (vel>xmax) xmax = vel;
  // start at zero
  int x = 0;
  // divide lower half
  int seg = (xzero-xmin)/(segs+zerohold);
  // find what segment we are in
  for(int i=0;i<segs+1;i++)
  {
    if (vel>=xzero-((segs-i)+zerohold)*seg) x=i;
  }
  // devide upper part
  seg = (xmax-xzero)/(segs+zerohold);
  // find what segment we are in
  for(int i=segs+1;i<2*segs+1;i++)
  {
     if (vel>=xzero+((i-segs-1)+zerohold)*seg) x=i;
  }
  // make X range from [-10,10] instead of [0,20]
  x-=segs;
  // invert X
  x=-x;
 
  // the same as before but with "Y" :-)
  vel = analogRead(Y);   
  if(vel<ymin) ymin=vel;
  else if (vel>ymax) ymax = vel;
  int y = 0;
  seg = (yzero-ymin)/(segs+1);
  for(int i=0;i<segs+1;i++)
  {
    if (vel>=yzero-((segs-i)+1)*seg) y=i;
  }
  seg = (ymax-yzero)/(segs+zerohold);
  for(int i=segs+1;i<2*segs+1;i++)
  {
    if (vel>=yzero+((i-segs-1)+zerohold)*seg) y=i;
  }
  y-=segs;
 /* map(velo, 1, 21, 0, 255);
/*  Serial.begin(9600);
  Serial.print("X"); Serial.println(A0); 
  delay(1000);
  int vel = analogRead(X);
  int dir = analogRead(Y);
  vel = map(vel, 170, 750, -255, 255);
  dir = map(dir, 0, 1023, -255, 255);
  vel = constrain(vel, 10, 254);
  dir = constrain(dir, -220, 220);*/
  if(X > 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, velo);
    analogWrite(E2, velo);
    delay(20);
  }
  if(X < 0)
  {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, velu);
    analogWrite(E2, velu);
    delay(20);
  }
}
