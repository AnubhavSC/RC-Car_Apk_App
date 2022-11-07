
 // Connect to the APP = "WIFI Rc Car", password = "Anubhav12"
 

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

//All Access Point details SSID with Password
const char* ssid = "WIFI Rc Car ";
const char* password = "Anubhav12";

//All pins details of the ESP8266 
#define ENA   4     // Pin num (D2)
#define IN_1  0     // Pin num (D3)
#define IN_2  2     // Pin num (D4)
#define IN_3  12    // Pin num (D6)
#define IN_4  13    // Pin num (D7)
#define ENB   15    // Pin num (D8)


String command;             // App command details.
int speedCar = 150; // 0 to 255
int speed_low = 60;

ESP8266WebServer server(80); // server start is port 80

void setup() { 
 
  Serial.begin(115200);

 pinMode(ENA, OUTPUT); 
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);
 pinMode(ENB, OUTPUT); 

 pinMode(Light, OUTPUT); 
 
  
// Connecting to the WiFi

  WiFi.mode(WIFI_AP);           // Access point
  WiFi.softAP(ssid, password);  //Starting HOTSport 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-Server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}
 // All commands details
 // I palce this command is the app E.g- for moving font word i use command "F"
void loop() {
    server.handleClient();
    
      command = server.arg("State");
           if (command == "F") goForword();         // "F" is the command for going forword 
      else if (command == "B") goBack();            // "B" is the command for going backward
      else if (command == "L") goLeft();            // "L" is the command for going Left
      else if (command == "R") goRight();           // "R" is the command for going Right 
      else if (command == "I") goForwordRight();    // "I" is the command for going Forword Right
      else if (command == "G") goForwordLeft();     // "G" is the command for going Forword Left
      else if (command == "J") goBackRight();       // "J" is the comnand for going Back Right
      else if (command == "H") goBackLeft();        // "H" is the command for going Back Left
      else if (command == "0") speedCar = 100;      // This are the speed bar limits (0 to 255)
      else if (command == "1") speedCar = 120;
      else if (command == "2") speedCar = 140;
      else if (command == "3") speedCar = 160;
      else if (command == "4") speedCar = 180;
      else if (command == "5") speedCar = 200;
      else if (command == "6") speedCar = 215;
      else if (command == "7") speedCar = 230;
      else if (command == "8") speedCar = 240;
      else if (command == "9") speedCar = 255;
      else if (command == "S") stopRobot();          // "S" is the command for Stop
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
 // This is the commands  for motors speed and direction 
void goForword(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goBack(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goLeft(){

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goForwordRight(){
      
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar-speed_low);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
   }

void goForwordLeft(){
      
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar-speed_low);
  }

void goBackRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar-speed_low);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goBackLeft(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar-speed_low);
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }

/* 
 * This is the code for the WIFI Control RC © Anubhav Shivam Nath 2022 
 * Anubhav Github repository - https://github.com/srsthryturnudurujhjbwerh/RC-Car_Apk_App
*/