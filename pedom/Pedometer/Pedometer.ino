int sensorPin = A0;   // voltage input. Use any ADC pin (starts with A)
int sensorValue = 0;  // stores value from ADC
int numSteps = 0;

int counter = 0;
int run_thresh = 5;

void setup()
{
  Serial.begin(115200);    // Opens serial port, Baud Rate 115200 bps
}

void loop()
{
  int sensorValue = analogRead (sensorPin);   // reads the sensor
  // returns 0-1023
  
  int minValue = 30;     // sensor value you consider to be minimum

  if (sensorValue > minValue) {
    numSteps++;
//    Serial.print("Steps: ");
//    Serial.println(numSteps);
    while(sensorValue > minValue) {
      sensorValue = analogRead (sensorPin);   // reads the sensor
      counter ++;
      Serial.print(counter);
      Serial.print("\t");
      delay(100);
    }
    if (counter > run_thresh){
      Serial.print("Walking! - Steps:");
    }else{
      Serial.print("Running! - Steps:");
    }
    counter = 0;
    numSteps++;
//    Serial.print("Steps: "); 
    Serial.println(numSteps);
    //delay(500);
    delay(100);
    
  }

//  Serial.println(sensorValue);   // Prints the value via the serial port

  delay(100);
}
