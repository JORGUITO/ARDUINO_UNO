//Definimos  los pines en los que tenemos conectadas las salidas del joystick  
const int ejeH = 0;          
const int ejeV = 1;   
  
void setup() {  
    // Inicializamos la comunicación serial  
    Serial.begin(9600);  
    }  
  
    void loop(){  
    //Mostramos las lecturas por la consola  
    Serial.print("EjeX: ");  
    Serial.println(analogRead(ejeH));  
    Serial.print ("EjeY: ");   
    Serial.println(analogRead(ejeV));
    Serial.println("------");
    delay(1500);  
}  
