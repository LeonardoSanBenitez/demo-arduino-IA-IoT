#include <SPI.h>      //to ethernet
#include <Ethernet.h>

//Pin definitions
#define PIN_LDR_1 A1
#define PIN_LDR_2 A2
#define PIN_BUTTON A3

// Global variables
int LDR1, LDR2, button;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // assign a MAC address for the ethernet controller.
char server[] = "arduino-demo.000webhostapp.com";
IPAddress ip(145, 14, 145, 236);            // Set the static IP address to use if the DHCP fails to assign

/** RESOURCE DECLARATIONS **/
EthernetClient client;

/*---------------------------------------------------------------------
  SETUP
---------------------------------------------------------------------*/
void setup() {
  pinMode(PIN_LDR1, INPUT);
  pinMode(PIN_LDR2, INPUT);
  pinMode(PIN_BUTTON, INPUT);

  /** SERIAL INIT **/
  Serial.begin(9600);
  while (!Serial) {;}
  Serial.println("Serial initialized");
  delay(100);

  /** START THE ETHERNET CONNECTION **/
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);  // try to congifure using IP address instead of DHCP:
  }
  Serial.println("Ethernet initialized");
  delay(1000);    // give the Ethernet shield a second to initialize
}

/*---------------------------------------------------------------------
  LOOP
---------------------------------------------------------------------*/
void loop() {
  LRD1 = analogRead(PIN_LDR_1);
  LRD2 = analogRead(PIN_LDR_2);
  button = analogRead(PIN_BUTTON);

  httpRequest();

  delay(20);
}



/*---------------------------------------------------------------------
  FUNCTION HTTP REQUEST
  Method used: GET
  ---------------------------------------------------------------------*/
void httpRequest() {
  // close any connection before send a new request. This will free the socket on the WiFi shield
  client.stop();

  Serial.print("Connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected!");
    // Make a HTTP request:
    client.print("GET /API_data_receive.php?");
    client.print("LDR1=");
    client.print(LDR1);
    client.print("&LDR2=");
    client.print(LDR2);
    client.print("&button=");
    client.print(button);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();
    Serial.println("Data sent: %d - %d - %d", LDR1, LDR2, button);
  } else {
    // if you didn't get a connection to the server:
    Serial.println("Connection failed");
  }
}












