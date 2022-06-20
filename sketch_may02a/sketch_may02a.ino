#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 7
#define TxD 6
#define LED_PIN 13
#define DEBUG_ENABLED  1
#define PIN_TEMP    A5
ZumoMotors motors;

SoftwareSerial blueToothSerial(RxD,TxD);

void setup()
{
    Serial.begin(9600);
    pinMode(RxD, INPUT);
    pinMode(TxD, OUTPUT);
    setupBlueToothConnection();
    Serial.print("started");
}
#define driving = false;
void loop()
{

    char recvChar;
    while(1)
    {
        if(blueToothSerial.available())
        {//check if there's any data sent from the remote bluetooth shield
            recvChar = blueToothSerial.read();
            Serial.println(recvChar);
            blueToothSerial.print("Help Me");
            if (recvChar == 'w' && !driving){
              ZumoMotors::setSpeeds(100,100 );
            }
            if (recvChar == 'w' && driving)
            {
              ZumoMotors::setSpeeds(0,0);
            }
            
            
        }
        if(Serial.available())
        {//check if there's any data sent from the local serial terminal, you can add the other applications here
            recvChar  = Serial.read();
            blueToothSerial.print(recvChar);
        }
    }


}



void setupBlueToothConnection()
{          
	blueToothSerial.begin(9600);  
	
	blueToothSerial.print("AT");
	delay(400); 

	blueToothSerial.print("AT+DEFAULT");             // Restore all setup value to factory setup
	delay(2000);
	
	blueToothSerial.print("AT+NAMESeeedBTSlave");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
	delay(400);
	
    blueToothSerial.print("AT+PIN0000");             // set the pair code to connect 
	delay(400);
	
	blueToothSerial.print("AT+AUTH1");             //
    delay(400);    

    blueToothSerial.flush();
}