# Handle-Arduino-With-Led-Button-and-temp-sensor

Controlling led using switch and Reading Tempreature using Tempreature sensor (LM36)

Components :

  1.Arduino UNO.
	
  2.LED.                                                            
	
  3.Push-button.
	
  4.Resistors.
	
  5.Temperture sensor (LM36).
	
  6.wires.


Circuit :

![capture](https://user-images.githubusercontent.com/20702455/42103549-b2a9628a-7bc9-11e8-9236-0d3e650b0dfb.PNG)


Operation :

Connect Led to Pin 13 and switch to pin 2 and connected as described in the circuit 
when you slide the switch it make the led light & send to serial monitor that " pressed " && "led on " 
which is work without any interfering with temp sensor (connect to A0) that send every 3 sec reading in VOLT , Celicuis , Fehrnhit 
to serial monitor which is configure to send at 9600 Bude Rate ( is a common measure of the speed of communication over a data channel bits /sec .)

To convert reading to voltage  as following :

  -Voltage at pin in milliVolts = (reading from ADC) * (5000/1024) 
  -This formula converts the number 0-1023 from the ADC into 0-5000mV (= 5V).

then Convert it to Celiuis as following :
  -from 10 mv per degree wit 500 mV offse to degrees ((voltage - 500mV) times 100).
 
then to Fehrnihit with the formula : (temperatureC * 9.0 / 5.0) + 32.0 .

With helping of millis(); Function it enable the program to run clearly without interfering as .

Code :
 As  illustrated at main.c file 
 i built 4 functions to handel the program functionality a
 nd with the help of built in functions as millis(); ,Serial.Println(""),attachInterrupt(),etc...
 
 this is a link of circuit simulation it is very useful to check :
 
 https://www.tinkercad.com/things/1b3iI0Tw70G 
 




