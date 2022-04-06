#include <VirtualWire.h>
#include <ServoTimer2.h>

#define motor 5 //把馬達連在引腳5

//#define ENA 5
//#define ENB 6
//#define IN2 8
//#define IN3 9

ServoTimer2 servo;

void setup() {
  Serial.begin(9600);
pinMode(motor,OUTPUT); // 設置馬達為狀態
servo.attach(9);

  vw_setup(2000);
  vw_rx_start();
  Serial.print("   o  ");   //433 to D11
}

void loop() {
 
  int valeurs[3];
  byte message = sizeof(valeurs);
  vw_wait_rx();

  if (vw_get_message((byte *) &valeurs, &message)){
    //valeurs[0]  轉向
    //valeurs[1]  油門
    //valeurs[2]  停機(沒用到)
    
 analogWrite(motor,map(valeurs[1], 0, 625, 0, 255));
 servo.write(map(valeurs[0], 0,180, 500, 2400));           //x軸搖桿（要用脈波寬度）

    Serial.print(valeurs[0]);   
    Serial.print("     ");
     Serial.print(valeurs[1]);   
     Serial.print("     ");
     Serial.println(valeurs[2]); 

  //delay(100);
  }  
}
