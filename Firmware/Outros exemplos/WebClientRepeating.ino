/*
  Repeating Web client

 This sketch connects to a a web server and makes a request
 using a Wiznet Ethernet shield. You can use the Arduino Ethernet shield, or
 the Adafruit Ethernet shield, either one will work, as long as it's got
 a Wiznet Ethernet module on board.

 This example uses DNS, by assigning the Ethernet client with a MAC address,
 IP address, and DNS address.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 19 Apr 2012
 by Tom Igoe
 modified 21 Jan 2014
 by Federico Vanzati

 http://www.arduino.cc/en/Tutorial/WebClientRepeating
 This code is in the public domain.

 */

#include <SPI.h>
#include <Ethernet.h>

// assign a MAC address for the ethernet controller.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
char server[] = "pi2engenharia.000webhostapp.com";
// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(145, 14, 145, 236);
IPAddress myDns(192, 168, 0, 1);
// initialize the library instance:
EthernetClient client;

//GLOBAL VARIABLES
char team[]="Elvis";
char instaled[]="LTPA";
int volume= 50;
char color[] = "2";

unsigned long lastConnectionTime = 0;           // last time you connected to the server, in milliseconds

//SETUP
void setup() {
    Serial.begin(9600);
  while (!Serial) {;}// wait for serial port to connect. Needed for native USB port only

  // give the ethernet module time to boot up:
  delay(1000);
  // start the Ethernet connection using a fixed IP address and DNS server:
  Ethernet.begin(mac, ip, myDns);
  // print the Ethernet board/shield's IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // read incoming data
  if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if x seconds have passed since your last connection, send data again
  if (millis() - lastConnectionTime > 1*1000) {
    httpRequest();
  }
}

void httpRequest() {
  // close any connection before send a new request. This will free the socket on the WiFi shield
  client.stop();

  if (client.connect(server, 80)) {   // connect method return true if successful connection 
    Serial.println("connecting...");
    client.print("GET /API_data_receive.php?");
    client.print("team=");
    client.print(team);
    client.print("&instaled=");
    client.print(instaled);
    client.print("&volume=");
    client.print(volume);
    client.print("ml");
    client.print("&color=");
    client.print(color);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();
    volume+=10;
    lastConnectionTime = millis();
  } else {
    Serial.println("connection failed");
  }
}
