int intensidad = 3; 
//int redPin = 11;
//int greenPin = 10;
//int bluePin = 9;
int i = A0;
int m = 0;
void setup()
{
  Serial.begin(9600); 
//  pinMode(redPin, OUTPUT);
//  pinMode(greenPin, OUTPUT);
//  pinMode(bluePin, OUTPUT);
  pinMode(intensidad, OUTPUT);  
}
 
void loop()
{
  Serial.print("LDR: ");  
  Serial.println(analogRead(i));  
  Serial.println("------");
  delay(1000);  
 // int i = (i / 4);
  i = analogRead(i);
  m = map(i, 0, 1023, 0, 255);
  analogWrite(intensidad, m);
//  digitalWrite(redPin, LOW);
//  analogWrite(greenPin, 255);
 // analogWrite(bluePin, 255); 
  delay(50);
}
