/**
 * The program read the values from the joystick (analog inputs!),
 * performs some auto-callibration and outputs X and Y as of an
 * intervall [-10,10].
 */

int joyPinX = 1;                 // X pin
int joyPinY = 0;                 // Y pin
int value = 0;                   // variable to hold the actual reading 
int xmin = 200;                  // X minimum value
int xmax = 800;                  // X maximum value
int ymin = 200;                  // Y minimum value
int ymax = 800;                  // Y maximum value
int xzero = 0;                   // the first X value (don't touch the joystick at startup!)
int yzero = 0;                   // the first Y value
int segs = 20;                   // number of intervalls to consider par half direction
double zerohold = 4;             // number of intervalls to consider as "zero position" 

void setup() 
{
  Serial.begin(115200);

  // do the first reading  
  yzero = analogRead(joyPinY);  
  xzero = analogRead(joyPinX);  
}



void loop() 
{
  // read the X value
  value = analogRead(joyPinX);   
  // push limits
  if(value<xmin) xmin=value;
  else if (value>xmax) xmax = value;
  // start at zero
  int x = 0;
  // divide lower half
  int seg = (xzero-xmin)/(segs+zerohold);
  // find what segment we are in
  for(int i=0;i<segs+1;i++)
  {
    if (value>=xzero-((segs-i)+zerohold)*seg) x=i;
  }
  // devide upper part
  seg = (xmax-xzero)/(segs+zerohold);
  // find what segment we are in
  for(int i=segs+1;i<2*segs+1;i++)
  {
     if (value>=xzero+((i-segs-1)+zerohold)*seg) x=i;
  }
  // make X range from [-10,10] instead of [0,20]
  x-=segs;
  // invert X
  x=-x;

  // the same as before but with "Y" :-)
  value = analogRead(joyPinY);   
  if(value<ymin) ymin=value;
  else if (value>ymax) ymax = value;
  int y = 0;
  seg = (yzero-ymin)/(segs+1);
  for(int i=0;i<segs+1;i++)
  {
    if (value>=yzero-((segs-i)+1)*seg) y=i;
  }
  seg = (ymax-yzero)/(segs+zerohold);
  for(int i=segs+1;i<2*segs+1;i++)
  {
    if (value>=yzero+((i-segs-1)+zerohold)*seg) y=i;
  }
  y-=segs;

  // print if on the screen
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("  -  Y = ");
  Serial.println(y);

  // wait some time
  delay(100);
}
