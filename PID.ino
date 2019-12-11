
//These represent the differen packages being utilized
#include <PID_v1.h>
#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <LiquidCrystal.h>

//defines pin output for MOSFET controlling heater voltage as a value (0, 255)
#define PIN_OUTPUT 2

//defines pins for adafruit thermocouple breakout board
#define MAXDO   3
#define MAXCS   4
#define MAXCLK  5

//all pins required for lcd output, no bit shifters
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Define Variables we'll be connecting to for PID control
double Setpoint, Input, Output;

//define thermocouple to retrieve sensor data
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

//Specify the links and initial tuning parameters and connect them to the PID library
double Kp=10, Ki=10, Kd=2;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //automatically sets the contrast
  //first number represents the associated pin, and the second number is the desired contrast amount
  analogWrite(6,150);

  //Start lcd and test
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("PID controller");
  delay(1500);

  //THIS IS THE TEMPERATURE SET POINT, how hot do you want it to be?
  Setpoint = 27;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{

  
  Input = thermocouple.readCelsius(); //read in temperature from thermocouple
  myPID.Compute();  //with given variables compute output as a value from 0 to 255
  float test = Output;  //captures output value to display on lcd

  //print output value being sent to mosfet/heater
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Output = ");
  lcd.println(test);

  //write the output to the mosfet controlling the heater, as a value from 0 to 255
  analogWrite(PIN_OUTPUT, Output);
  lcd.setCursor(0, 1);

  //tests to see if the temperature read is valid, if not it will display an error
  if (isnan(Input)) 
   {
     lcd.print("T/C Problem");
   } 
   else 
   {

     //print temperature of thermocouple
     lcd.print("C = "); 
     lcd.print(Input);
     
 
   }

  //pause in milliseconds
  delay(1000);

  
}
