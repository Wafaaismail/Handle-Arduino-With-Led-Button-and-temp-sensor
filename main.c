/*
**Arduino function to control one input and output (IO Pins)
  the input pin is a switch as interrupt once it pressed it should lighting the led connected to output pin.

**if the switch pressed must send “pressed” to the serial monitor only one time also send the LED states ”ON” or “OFF”

**the whole function could be used many times in the program without interfering each-other
** send continuous serial date comes from temperature sensor with 3 second rate .at the same time
*/

/***********************VARIABLES*************************/

const byte ledPin = 13;                     //connect led to pin 13
const byte interruptPin = 2;               //connect switch to pin 2

volatile byte state = 0;                   //switch current state
int oldCheck = 0;                         //switch old state
int sensorPin = 0;
int reading;

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 3000;           // interval at which temp send to serial (milliseconds)

/***********************Prototypes*************************/
void checkInterval(unsigned long currentMillis);
void checkState(int state);
void blink();
void tempSensor(int reading);

/*************************BODY****************************/
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);

  Serial.begin(9600);   //start make connection with serial monitor with bude rate 9600

}

void loop()
{
  reading = analogRead(sensorPin);              //read temp sensor value

  unsigned long currentMillis = millis();          //save currrent time
  checkInterval(currentMillis);
  digitalWrite(ledPin, state);                     //led operation
  checkState(state);

}
/******* function help to send temp sensor every 3 sec  ( fixed interval )depend on
  the current time reading and the previous time you read the sensor**************/
void checkInterval(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= interval) {
    tempSensor(reading);
    previousMillis = currentMillis;
  }

}
/********************function to check state of led and print on serial
when you press the switch and the current state of the led ****************/
void checkState(int state) {
  int check = state;

  if (state == 1 ) {
    if (check != oldCheck) {
      Serial.println("-------------------");
      Serial.println("pressed");
      Serial.println("Led On");
      Serial.println("-------------------");
    }
  }
  if (state == 0 ) {
    if (check != oldCheck) {
      Serial.println("-------------------");
      Serial.println("pressed");
      Serial.println("Led Off");
      Serial.println("-------------------");
    }
  }
  oldCheck = check;

}

/********function to toggele led state*********/
void blink()
{
  state = !state;

}
/***********this function take the reading of sensor convert it to volt
then to Celecius and Fahrenheit and print at serial ************************/
void tempSensor(int reading) {

  float voltage = reading * 5.0;
  voltage /= 1024.0;
  //  print out voltage
  Serial.print(voltage); 
  Serial.println(" volts");
  
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;
  //converting from 10 mv per degree wit 500 mV offset to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); 
  Serial.println(" degrees C");
  
  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.println(" degrees F");
}
