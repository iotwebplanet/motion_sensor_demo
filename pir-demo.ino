/*
* All components availble at iotwebplanet.com
*/

/*
 * Connection Details
 * 
 * PIR Sensor pin             Arduino Uno pin
 * GND                        GND
 * VCC                        5v
 * OUTPUT                     4
 * 
 * Buzzer pin
 * VCC(+)                     13
 * GND                        GND
 * 
 */


 
int buzzer = 13;                // choose the pin for the LED
int sensor = 4;               // choose the sensor input pin (for PIR sensor)
int sensorState = LOW;             // default assuming no motion detected
int val = 0;                    // variable for reading the sensor data
 
void setup() {
  pinMode(buzzer, OUTPUT);      // declare LED as output
  pinMode(sensor, INPUT);     // declare sensor as input
 
  Serial.begin(9600);   //for debug
}
 
void loop(){
  val = digitalRead(sensor);                      // read sensor input value
  if (val == HIGH) {                             // check if the sensor is HIGH
    digitalWrite(buzzer, HIGH);                 // turn Buzzer/light ON
    if (sensorState == LOW) {                  // we have just turned on
      Serial.println("Motion detected!");     // We only want to print on the output change, not state
      sensorState = HIGH;
    }
  } else {
    digitalWrite(buzzer, LOW);           // turn Light/Buzzer OFF
    if (sensorState == HIGH){           // we have just turned of
      Serial.println("Motion ended!"); // We only want to print on the output change, not state
      sensorState = LOW;
    }
  }
}
