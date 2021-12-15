
#include <ESP8266WiFi.h> 
#include <FirebaseArduino.h> 
#include<WiFiClient.h> 
#include<ESP8266WebServer.h> 
#include<ESP8266mDNS.h> 
 
 int receptorWifi = 0; 
int transmisorWifi = 1; 
int receptorBluetooth = 2 
int transmisorBluetooth = 3; 
int sensorMovimiento = 4; 
 
#define FIREBASE_HOST "virtual-trainer-e2a72-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "ikJtzOabSgyLN2VwepKUuI6yVTLqWY0KLcT1oyiK" 
#define WIFI_SSID "SSID"   // usuario wifi 
#define WIFI_PASSWORD "PASSWORD"   // contraseña 
 
 int Bombillo1 = 8; 
int Bombillo2 = 9;  
int Bombillo3 = 10;  
int Bombillo4 = 11; 
int estado1,estado2,estado3,estado4; 
 
 public bool movimiento;  
 
 void setup() { 
  Serial.begin(9600); 
 
   // connect to wifi. 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
  } 
  Serial.println(); 
  Serial.print("connected: "); 
  Serial.println(WiFi.localIP()); 
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
 
  pinMode(receptorWifi , INPUT);  
  pinMode(transmisorWifi , OUTPUT);  
  pinMode(receptorBluetooth , INPUT);  
  pinMode(transmisorBluetooth , OUTPUT); 
  pinMode(sensorMovimiento , INPUT); 
  pinMode(Bombillo1 , OUTPUT); 
  pinMode(Bombillo2 , OUTPUT); 
  pinMode(Bombillo3 , OUTPUT); 
  pinMode(Bombillo4 , OUTPUT); 
} 
 
 void loop() { 
 
  estado1 = Firebase.getInt("bombillo1"); 
  estado2 = Firebase.getInt("bombillo2"); 
  estado3 = Firebase.getInt("bombillo3"); 
  estado4 = Firebase.getInt("bombillo1"); 
 
 if(digitalRead(sensorMovimiento == HIGH){ 
     
      Serial.println("Se detecto Movimiento") 
      digitalWrite(Bombillo, HIGH); 
      movimiento = true; 
     
    } 
 
 // A continuaci?n seg?n la informaci?n que recibimos via bluetooth o wifi enviamos voltaje por los puertos de arduino 
  switch(estado1){ 
   
    // Para en el caso que la variable sea  1 encenderemos Bombillo 
    case 1:  
    digitalWrite(Bombillo1, HIGH); 
    break; 
 
  // Para en el caso que la variable sea  2 apagaremos Bombillo 
    case 2:  
    digitalWrite(Bombillo1, LOW); 
    break; 
  } 
  switch(estado2){ 
    case 1:  
    digitalWrite(Bombillo2, HIGH); 
    break; 
 
  case 2:  
    digitalWrite(Bombillo2, LOW); 
    break; 
 
   } 
  switch(estado3){ 
        case 1:  
    digitalWrite(Bombillo3, HIGH); 
    break; 
 
     case 2:  
    digitalWrite(Bombillo3, LOW); 
    break; 
  } 
  switch(estado4){ 
        case 1:  
    digitalWrite(Bombillo4, HIGH); 
    break; 
 
     case 2:  
    digitalWrite(Bombillo4, LOW); 
    break; 
 
   } 
} 
 

