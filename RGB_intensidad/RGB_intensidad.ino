int intensidad = 3; 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int i = 0; 
int m = 0;
void setup()
{
  Serial.begin(9600); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(intensidad, OUTPUT);
  
}
 
void loop()
{
  i = analogRead(A2);
  m = map(i, 0, 400, 0, 255);
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
  
}
  /*
  setColor(255, 0, 0);  // red
  delay(5000);
  setColor(0, 255, 0);  // green
  delay(5000);
  setColor(0, 0, 255);  // blue
  delay(5000);
  setColor(255, 255, 0);  // yellow
  delay(5000);  
  setColor(80, 0, 80);  // purple
  delay(5000);
  setColor(0, 255, 255);  // aqua
  delay(5000);
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}*/
