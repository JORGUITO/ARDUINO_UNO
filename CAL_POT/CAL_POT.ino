 
int analogPin = A0;     // el pin analógico 3 conectado al dial de un potenciómetro (terminal central del potenciómetro) 
                       // los terminales exteriores del potenciómetro conectados a +5V y masa respectivamente
int val = 0;           // declaración de la variable en la que se almacenará el valor leído por el conversor.

void setup()
{
  Serial.begin(9600);          //  Inicialización del modulo Serial.
}

void loop()
{
  val = analogRead(analogPin);    // lee el valor de tensión del pin
  Serial.println(val);             // envía el valor leido vía serial.
  delay(900);
}

