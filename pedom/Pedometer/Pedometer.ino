int sensorPin = A0;   // voltage input. Use any ADC pin (starts with A)
int sensorValue = 0;  // stores value from ADC

int numSteps = 0;   // tracks number of steps taken
int counter = 0;    // tracks how long since the last step was taken

int minValue = 30;     // minimum sensor value for a complete weight shift
int run_thresh = 4;    // maximum duration to be considered running

void setup()
{
  Serial.begin(115200);    // Opens serial port, Baud Rate 115200 bps
}

void loop()
{
  int sensorValue = analogRead (sensorPin);   // reads the sensor
  // returns 0-1023

  counter++;

  // weight shift to sensored foot
  if (sensorValue > minValue) {
    if (counter > run_thresh) {
      Serial.print("Walking! - Steps: ");
    } else {
      Serial.print("Running! - Steps: ");
    }
 
    numSteps++;
    Serial.println(numSteps);
    counter = 0;
    
    while (sensorValue > minValue) {
      sensorValue = analogRead (sensorPin);   // reads the sensor
      counter++;
      delay(100);
    }
    
    // weight shift to non-sensored foot
    if (counter > run_thresh) {
      Serial.print("Walking! - Steps: ");
    } else {
      Serial.print("Running! - Steps: ");
    }
    
    numSteps++;
    Serial.println(numSteps);
    counter = 0;
    
    delay(100);
  }

  delay(100);
}
