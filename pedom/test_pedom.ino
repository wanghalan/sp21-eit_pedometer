int ledPin = 9;    // output to LED. Use any PWM-enabled pin (marked ~)
int sensorPin = A0;   // voltage input. Use any ADC pin (starts with A)
int sensorValue = 0;  // stores value from ADC


int sensorHigh = 300;
int sensorLow = 0;
int tolerance = 25;
int sensorMode= 0;

void setup()      
{
   Serial.begin(115200); 
   pinMode(ledPin, OUTPUT);    
}

void loop()    
{
   int sensorValue = analogRead (sensorPin);   // reads the sensor

   if (sensorMode== 0){
      if (sensorValue > (sensorHigh - tolerance)){
        sensorMode= 1;
        analogWrite(ledPin, 255);
      }
   }else{
      if (sensorValue < (sensorLow + tolerance)){
        sensorMode= 0;
        analogWrite(ledPin, 0); 
      }
   }
   Serial.print(sensorValue); 
   Serial.print("\t"); 
   Serial.println(sensorMode); 

   delay(10);     
}  
