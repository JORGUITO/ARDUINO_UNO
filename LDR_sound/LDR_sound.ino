int speakerPin = 8;
int photocellPin = 0;
 
void setup()
{
}
 
void loop()
{
int reading = analogRead(photocellPin);
int pitch = 200 + reading / 4;
tone(speakerPin, pitch);
}
