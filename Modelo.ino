#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include<ESP8266mDNS.h>
#includer <WiFi.h>

int receptorWifi = 0;
int transmisorWifi = 1;
int receptorBluetooth = 2
int transmisorBluetooth = 3;
int sensorMovimiento = 4;

char nombreWifi;
char password;


int Bombillo = 8; 

public bool movimiento; 


int estado = 0;

void setup(){

Serial.begin(9600);

pinMode(receptorWifi , INPUT); 
pinMode(transmisorWifi , OUTPUT); 
pinMode(receptorBluetooth , INPUT); 
pinMode(transmisorBluetooth , OUTPUT);
pinMode(sensorMovimiento , INPUT);
pinMode(Bombillo , OUTPUT);

ConnectWiFi();

}

void loop(){

	if(Serial.available() > 0 ){

		estado = Serial.read(); 

	}

	if(digitalRead(sensorMovimiento == HIGH){
		
			Serial.println("Se detecto Movimiento")
			digitalWrite(Bombillo, HIGH);
			movimiento = true;
		
		}

// A continuaci?n seg?n la informaci?n que recibimos via bluetooth enviamos voltaje por los puertos de arduino
	switch(estado){
	
		// Para en el caso que la variable sea  1 encenderemos Bombillo
		case 1: 
		digitalWrite(Bombillo, HIGH);
		break;

		// Para en el caso que la variable sea  2 apagaremos Bombillo
		case 2: 
		digitalWrite(Bombillo, LOW);
		break;


	}
}

void ConnectWiFi()
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(nombreWifi, password);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(nombreWifi);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}


