int temp = 0;  //Pin analógico A0 donde conectaremos el pin de datos del sensor LM35
float maxC = 0, minC = 100, maxF = 0, minF = 500;  //Variables para ir comprobando maximos y minimos

void setup()
{
  Serial.begin(9600);  //Iniciamos comunicación serie con el Arduino para ver los resultados del sensor
  //a través de la consola serie del IDE de Arduino
}

void loop()
{
  float gradosC, gradosF;  //Declaramos estas variables tipo float para guardar los valores de lectura

  gradosC = (5.0 * analogRead(temp) * 100.0) / 1024;  //Esta es la funcion con la que obtenemos la medida del sensor
  // en ºC

  gradosF = (gradosC * 1.8) + 32;  //Multiplicando los ºC por 1.8 y luego sumando 32 obtenemos grados Fahrenheit

  //Mostramos mensaje con valores actuales de temperatura, asi como maximos y minimos de cada uno de ellos
  Serial.print("Temp actual\n");
  Serial.print("C: ");
  Serial.print(gradosC);
  Serial.print("\tF: ");
  Serial.print(gradosF);
  //Comprobacion de maximos y minimos de temperatura
  if (maxC < gradosC)
    maxC = gradosC;
  if (gradosC < minC)
    minC = gradosC;
  if (maxF < gradosF)
    maxF = gradosF;
  if (gradosF < minF)
    minF = gradosF;
  Serial.print("\nTemp max\n");
  Serial.print("C: ");
  Serial.print(maxC);
  Serial.print("\tF: ");
  Serial.print(maxF);
  Serial.print("\nTemp min\n");
  Serial.print("C: ");
  Serial.print(minC);
  Serial.print("\tF: ");
  Serial.print(minF);
  Serial.print("\n\n");
  delay(5000);  //Usamos un retardo de 2 segundos entre lectura y lectura
}

