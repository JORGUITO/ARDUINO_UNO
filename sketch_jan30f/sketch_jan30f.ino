#define LDR 0
#define LED 3 //es una de las salidas PWM

int valor_ldr, valor_led;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  valor_ldr = analogRead(LDR);
  valor_led = map(valor_ldr,130,320,0,255);
  analogWrite(LED, valor_led);
  delay(100);
}

