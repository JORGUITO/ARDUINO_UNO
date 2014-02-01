int luz;                    //DECLARACIÓN DE VARIABLES
int led;
int i=0;
 
void setup()
{
 Serial.begin(9600);        //VELOCIDAD DE COMUNICACIÓN CON EL PC
 pinMode(3,OUTPUT);         //DECLARAMOS 4 SALIDAS CON PWM COMO DE SALIDA
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(9,OUTPUT);
 
 digitalWrite(3,HIGH);      //HACEMOS UNA COMPROBACIÓN DE FUNCIONAMIENTO DE LOS 4 LED
 delay(200);                //ANTES DE EMPEZAR CON EL PROGRAMA
 digitalWrite(3,LOW);
  
 digitalWrite(5,HIGH);
 delay(200);
 digitalWrite(5,LOW);
  
 digitalWrite(6,HIGH);
 delay(200);
 digitalWrite(6,LOW);
  
 digitalWrite(9,HIGH);
 delay(200);
 digitalWrite(9,LOW);
  
}
void loop()
{
luz=analogRead(A2);         //LEEMOS EL NIVEL DE ILUMINACIÓN EN EL LDR
if(luz<400)                 //ESTABLECEMOS UN NIVEL DE ILUMINACIÓN MINIMO A PARTIR DEL CUAL
{                           //REACCIONARÁN LOS LED
led=map(luz,0,400,255,0);   //HACEMOS UNA INTERPOLACIÓN ENTRE LA SEÑAL DEL LDR Y LA ILUMINACIÓN
}
else{led=0;}                //POR ENCIMA DEL VALOR MINIMO, LOS LED NO SE ENCIENDEN
 
analogWrite(3,led);         //QUE CADA LED ILUMINE SEGÚN LO ANTERIOR
analogWrite(5,led);
analogWrite(6,led);
analogWrite(9,led);
 
i=i+1;          //PARA NO LLENAR LA PANTALLA DE LINEAS DE INFORMACIÓN, CADA VEZ QUE EL
if (i%2000==0)  //PROGRAMA EJECUTE 2000 VECES, QUE IMPRIMA EN PATALLA LOS VALORES DE luz y DE led
{
  Serial.print("Nivel de luz: ");Serial.println(luz);
  Serial.print("Salida PWM: ");Serial.println(led);
} 
}
