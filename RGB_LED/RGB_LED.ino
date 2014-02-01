// RGB LED night light  Arduino

// Arduino pins para motor y LEDs
#define MOTOR 3
#define RED 9 //147 ohm
#define GREEN 10 //82 ohm
#define BLUE 11 //82 ohm

// pins for motor and LEDs are outputs
void setup() {
  pinMode(MOTOR, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  //  motor speed, de 0 a 255
  analogWrite(MOTOR, 255);

  // fade de aqua a magenta
  for (int i = 0; i < 256; i++) {
    analogWrite(RED, 255-i);
    analogWrite(GREEN, i);
    analogWrite(BLUE, 0);
    delay(50);
  }

  // fade de magenta a aqua
  for (int i = 0; i < 256; i++) {
    analogWrite(RED, i);
    analogWrite(GREEN, 255-i);
    analogWrite(BLUE, 0);
    delay(50);
  }

}
