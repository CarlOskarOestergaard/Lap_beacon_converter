#include <FlexCAN_T4.h>


// Dette er lavet i en branch



// CAN settings
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;  // can1 port

IntervalTimer timer;

// Variables CAN RX
int msg0 = 0;
int msg1 = 0;
int msg2 = 0;
int msg3 = 0;
int msg4 = 0;
int msg5 = 0;
int msg6 = 0;
int msg7 = 0;

int msg0_old = 0;

// Variables CAN TX
int can500Byte0_1 = 0;
int can500Byte2_3 = 0;
int can500Byte4_5 = 0;
int can500Byte6_7 = 0;

int OnTime = 0;

int ledpinStatus = 0;
int beaconPinStatus = 0;

int ledPin = 12;
int beaconPin = 1;


//Timer for get VESC UART
long interval           = 20;
long interval_LED       = 1000;
long interval_beacon    = 20;
long interval_100ms     = 100;

long currentMillis      = 0;
long previousMillis_LED = 0;
long previousMillis_100ms = 0;
long previousMillis_beacon = 0;
long delta = 0;


// Debug ON/OFF
int CSV = 0;                                         // Enables serial.print to print in CSV format

int i = 0;

int RX_can = 0;

void setup()
{
  Serial.begin(19200);                               // Setup Serial monitor for PC

  pinMode(ledPin, OUTPUT);
  pinMode(beaconPin, OUTPUT);


  //CAN settings
  can1.begin();
  can1.setBaudRate(1000000);
  can1.enableFIFO();
  can1.enableFIFOInterrupt();
  can1.onReceive(canSniff);
  delay(1000);
  timer.begin(sendframe, 100000);                 // Call the function: Sendframe, every 100ms
}

void loop()
{
  currentMillis = millis();                          //Used for interrupt timer for UART
  can1.events();                                     //I have no idea what this does :-)

  if (currentMillis - previousMillis_100ms > interval_100ms)
  {
    previousMillis_100ms = currentMillis;
    i = i + 1;
  }

  can500Byte0_1 = millis();                           //On time in milli seconds
  can500Byte2_3 = msg0;                               //Copy of Lapnumber
  can500Byte4_5 = ledpinStatus;                       //Status of the physical LED output
  can500Byte6_7 = beaconPinStatus;                    //Status of the physical Beacon output


  if (CSV == 1)
  {
    PrintCSV();                                       //Debug to Serial print, formatted as CSV
  }

  if (i > 10)
  {
    LED("flash"); // flash
  }

  if (i < 10)
  {
    LED("on"); // ON
  }

  beaconOutput();

}
