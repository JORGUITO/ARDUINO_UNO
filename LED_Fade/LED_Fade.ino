// Variar la intensidad de un LED usando un salida PWM
int PWMpin = 10; // En el pin 10 hay un LED en serie con una resistencia de 470 ohmios

void setup()
{
  // no es necesario nada aquí
}
void loop()
{
   int x = 1;
   for (int i = 0; i > -1; i = i + x){
      analogWrite(PWMpin, i);
      if (i = 255) x = -1;             // cambia de signo para apagarlo
      delay(10);
   } 
}
