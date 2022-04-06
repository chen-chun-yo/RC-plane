#include <VirtualWire.h>
#include<math.h>

void setup() {
  Serial.begin(9600);
   pinMode(13,INPUT);                  //startbutton
   //pinMode(52,INPUT_PULLUP);                  //startbutton
  vw_setup(2000);
}
 
void loop() {
  int valeurs[3];
  int k;
  k=map(analogRead(2), 0, 1023, 625, 0);
 valeurs[0] = map(analogRead(5), 0, 1023, 0, 180); //轉向
 valeurs[1] = sqrt(sqrt(k))  *125 ;       //fuel
 valeurs[2] = digitalRead(13);       //停機button

Serial.print(valeurs[0] );
  Serial.print("  " );
Serial.print(valeurs[1] );
  Serial.print("  " );
Serial.println(valeurs[2]);
  

   
  vw_send((byte *) &valeurs, sizeof(valeurs)); 
    Serial.print("  v" );
  vw_wait_tx(); 
  
  delay(50);
}
