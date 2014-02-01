//--- bof RGBL - RGB Digital Preamble
//RGB LED pins
int ledDigitalOne[] = {14, 15, 16};
//the three digital pins of the first digital LED 14 = redPin, 15 = greenPin, 16 = bluePin
int ledDigitalTwo[] = {9, 10, 11};
//the three digital pins of the first digital LED 14 = redPin, 15 = greenPin, 16 = bluePin
int ledDigitalThree[] = {3, 5, 6};
//the three digital pins of the first digital LED 14 = redPin, 15 = greenPin, 16 = bluePin
const boolean ON = LOW;
//Define on as LOW (this is because we use a common Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;
//Define off as HIGH
//Predefined Colors
const boolean RED[] = {ON, OFF, OFF};
const boolean GREEN[] = {OFF, ON, OFF};
const boolean BLUE[] = {OFF, OFF, ON};
const boolean YELLOW[] = {ON, ON, OFF};
const boolean CYAN[] = {OFF, ON, ON};
const boolean MAGENTA[] = {ON, OFF, ON};
const boolean WHITE[] = {ON, ON, ON};
const boolean BLACK[] = {OFF, OFF, OFF};

//An Array that stores the predefined colors (allows us to later randomly display a color)
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};
//--- eof RGBL - RGB Digital Preamble

void setup(){
for(int i = 0; i < 3; i++) {
pinMode(ledDigitalOne[i], OUTPUT);
//Set the three LED pins as outputs
pinMode(ledDigitalTwo[i], OUTPUT);
//Set the three LED pins as outputs
pinMode(ledDigitalThree[i], OUTPUT);
//Set the three LED pins as outputs
}
}

void loop(){

/* Example - 1 Set a color Set the three LEDs to any predefined color*/
setColor(ledDigitalOne, RED);
//Set the color of LED one
setColor(ledDigitalTwo, GREEN);
//Set the color of LED two
setColor(ledDigitalThree, BLUE);
//Set the color of LED three

/* Exampe - 2 Go through Random Colors Set the LEDs to a random color*/
int rand = random(0, sizeof(COLORS) / 2);
//get a random number within the range of colors
setColor(ledDigitalOne, COLORS[rand]);
//Set the color of led one to a random color
rand = random(0, sizeof(COLORS) / 2);
//Set the color of LED 2 to a random color //
setColor(ledDigitalTwo, COLORS[rand]);
rand = random(0, sizeof(COLORS) / 2);
//Set the color of LED 3 to a random color //
setColor(ledDigitalThree, COLORS[rand]);
delay(1000);
}

/* Sets an led to any color led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin) color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)*/
void setColor(int* led, boolean* color){
for(int i = 0; i < 3; i++) {
digitalWrite(led[i], color[i]);
}
}
/* A version of setColor that allows for using const boolean colors*/
void setColor(int* led, const boolean* color) {
boolean tempColor[] = {color[0], color[1], color[2]};
setColor(led, tempColor);
}
