int ledPin = 9;    // output to LED. Use any PWM-enabled pin (marked ~)
int sensorPin = A0;   // voltage input. Use any ADC pin (starts with A)
int sensorValue = 0;  // stores value from ADC
bool sensorOn= true;
int threshold = 0;

void setup()      
{
   Serial.begin(115200);    // Opens serial port, Baud Rate 115200 bps
   pinMode(ledPin, OUTPUT);    
}

void loop()    
{
   int sensorValue = analogRead (sensorPin);   // reads the sensor

                                                // returns 0-1023  
   int minValue = 0;     // sensor value you consider to be minimum
   int maxValue = 1023;    // sensor value you consider to be maximum

   int constrainedValue = constrain(sensorValue, minValue, maxValue);

    if (constrainedValue > threshold){
        if (sensorOn){
          analogWrite(ledPin, 0); 
        }else{
          analogWrite(ledPin, 255); 
        }
        sensorOn = !sensorOn;
        delay(500);
    } 
}  
