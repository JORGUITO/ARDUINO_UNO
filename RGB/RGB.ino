/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
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
}
