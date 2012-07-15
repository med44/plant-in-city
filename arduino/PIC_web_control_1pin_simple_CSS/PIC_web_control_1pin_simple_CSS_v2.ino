//zoomkat 9-5-11
//simple button GET with iframe code
//for use with IDE 0021
//open serial monitor to see what the arduino receives
//use the \ slash to escape the " in the html 
//address will look like http://192.168.1.102:84/ when submited
//for use with W5100 based ethernet shields

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x7C, 0xA2};
byte ip[] = {192,168,1,120};
//byte ip[] = {1};
EthernetServer server(80);
EthernetClient client;


String readString;
int ledPin = 3;

//////////////////////

void setup(){

  pinMode(3, OUTPUT); //pin selected to control
  //start Ethernet
  Ethernet.begin(mac, ip);
  server.begin();

  //enable serial data print 
  Serial.begin(9600); 
  Serial.println("servertest1"); // so I can keep track of what is loaded
}

void loop(){
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100) {

          //store characters to string 
          readString += c; 
          //Serial.print(c);
        } 

        //if HTTP request has ended
        if (c == '\n') {

          ///////////////
          Serial.println(readString); //print to serial monitor for debuging 

          //now output HTML data header
             if(readString.indexOf('?') >=0) { //don't send new page
               client.println("HTTP/1.1 204 Zoomkat");
               client.println();
               client.println();  
             }
             else {
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();

          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE>Plant-in City Web Control</TITLE>");
          client.println("<meta charset=\"UTF-8\">");
          client.println("<meta name=\"viewport\" content=\"initial-scale=1.0, user-scalable=no\" />");
          //client.println("<meta name=\"viewport\" content=\"width = 640\" />");
          client.println("<style media=\"screen\" type=\"text/css\">");
          client.println("body { color: #d6db95; background-color: #6d7f36; font-family: Arial, Helvetica, sans-serif; font-size: medium; font-weight:normal }");
          client.println("a { text-decoration:none }");
          client.println("#button_arduino { margin: 20px; background-color: #ffffcc; height: 60px; width: 60%; padding-top: 30px; border-width: 1px; border-radius: 15px; color: #333300; font-size: x-large; font-weight: bold; vertical-align:middle }");
          client.println("</style>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<center>");
          client.println("<H1>Water</H1>");
          
          client.println("<a href=\"/?on\" target=\"inlineframe\"><div id=\"button_arduino\">ON</div></a>"); 
          client.println("<a href=\"/?off\" target=\"inlineframe\"><div id=\"button_arduino\">OFF</div></a>"); 
//          client.println("<a href=\"/?on\">ON</a></br>"); 
//          client.println("<a href=\"/?off\">OFF</a>");

//          client.println("<IFRAME name=inlineframe src=\"res://D:/WINDOWS/dnserror.htm\" width=1 height=1\">");
          client.println("<IFRAME name=inlineframe style=\"display:none\" >");          
          client.println("</IFRAME>");
          client.println("</center>");
          client.println("</BODY>");
          client.println("</HTML>");
             }

          delay(1);
          //stopping client
          client.stop();

          ///////////////////// control arduino pin
          if(readString.indexOf("on") >0)//checks for on
          {
              digitalWrite(3, HIGH);    // set ledPpin high
              Serial.println("Led On");
            }  
            
          if(readString.indexOf("off") >0)//checks for off
          {
            digitalWrite(3, LOW);    // set ledPin low
            Serial.println("Led Off");
          }
          //clearing string for next read
          readString="";

        }
      }
    }
  }
} 

