#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int led2 = 10;
int led = 40;


void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
  pinMode(led, OUTPUT);
  pinMode(led2,OUTPUT); 
  
  digitalWrite(led, LOW);
  digitalWrite(led2,LOW);
  
  
  
}


void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Lekerdezes...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("KESZ");
  
  Serial.print("[1] Homero: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.println(" Celsius");
  
  Serial.print("[2] Homero: ");
  Serial.print(sensors.getTempCByIndex(1)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.println(" Celsius");
  
  if (sensors.getTempCByIndex(1) > 22) {
    digitalWrite(led, HIGH);
        digitalWrite(led2, HIGH);
  }
  else {
    digitalWrite(led, LOW);
        digitalWrite(led2, LOW);
  }
   
}
