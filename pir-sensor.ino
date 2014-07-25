/*
 * Connected sensor
 * Spark.publish() + PIR motion sensor = awesome
 */

int inputPin = D0;              // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int calibrateTime = 10000;      // wait for the thingy to calibrate
int led = D7;

void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(led, OUTPUT);
}

void loop(){

  if (calibrated()) {
    readTheSensor();
    reportTheData();
  }
}

bool calibrated() {
  return millis()-calibrateTime>0;
}

void readTheSensor() {
  val = digitalRead(inputPin);
       
}

void reportTheData() {
  if (val == HIGH) {
    if (pirState == LOW) {
      // we have just turned on

      Spark.publish("motion");
      // We only want to print on the output change, not state
      pirState = HIGH;
            digitalWrite(led,HIGH); 
    }

  } else {
    if (pirState == HIGH) {
      // we have just turned of

      // We only want to print on the output change, not state
      pirState = LOW;
      digitalWrite(led,LOW); 
    }
     
  }
}

