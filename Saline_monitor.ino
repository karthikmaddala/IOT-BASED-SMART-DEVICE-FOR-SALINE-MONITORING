#include <HX711_ADC.h> // https://github.com/olkal/HX711_ADC
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
int flag=0,flag1=0,flag2=0,flag3=1,flag4=1,flag5=1;
HX711_ADC LoadCell(4, 5); // parameters: dt pin, sck pin<span data-mce-type="bookmark" style="display: inline-block; width: 0px; overflow: hidden; line-height: 0;" class="mce_SELRES_start"></span>
LiquidCrystal_I2C lcd(0x3F,16,2); // 0x27 is the i2c address of the LCM1602 IIC v1 module (might differ)
void setup() {
  Serial.begin(9600);

  mySerial.begin(9600);
  float i;
    lcd.init();
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(419); // calibration factor for load cell => strongly dependent on your individual setup
  lcd.begin(16, 2); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight
   
}

void loop() {
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
  lcd.setCursor(0, 0); // set cursor to first row
  i=i;
  lcd.print("Weight[g]:"); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to secon row
  lcd.print(i); // print out the retrieved value to the second row
  if(i>50){
  flag=1;}
  if(flag){
if (i<55){
  if(flag3==1){
      lcd.init();
      lcd.print("threshold reached 50");
       mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+91123456789\"\r"); // Replace x with mobile number
     delay(1000);
     Serial.println("threshold reached");
   //  mySerial.println("threshold reached ");
     mySerial.print("the level is :");
     mySerial.println(i);
  //  mySerial.print("immediately goto room no:126");
     // The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      flag3=0;}

}}
if(i>21){
  flag1=1;}
  if(flag1){
if (i<20){
  if(flag4==1){
      lcd.init();
      lcd.print("threshold reached 20");
       mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+91123456789\"\r"); // Replace x with mobile number
     delay(1000);
     Serial.println("threshold reached");
    // mySerial.println("threshold reached ");
     mySerial.print("the level is :");
     mySerial.println(i);
   // mySerial.print("immediately goto room no:126");
     // The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      flag4=0;}

}}
if(i>10){
  flag2=1;}
  if(flag2){
if (i<10){
  if(flag5==1){
      lcd.init();
      lcd.print("threshold reached 10 ");
       mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+91123456789\"\r"); // Replace x with mobile number
     delay(1000);
     Serial.println("threshold reached");
     mySerial.println("threshold reached");
     mySerial.print("the level is :");
     mySerial.println(i);
    mySerial.print("immediately goto room no:126");
     // The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      flag5=0;}

}}}
