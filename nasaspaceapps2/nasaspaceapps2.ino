#include <Wire.h>  // Comes with Arduino IDE

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int t;
int t1=0;
void setup()   
{
  Serial.begin(9600);  

  lcd.begin(20,4);         

  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); 
  lcd.setCursor(3,0); 
  lcd.print("Air Care ONLINE");
  delay(1000);
  lcd.setCursor(2,1);
  lcd.print("SERVER IS UP");
  delay(1000);  
  lcd.setCursor(0,2);
  lcd.print("SENSOR OK");
  lcd.setCursor(0,3);
  delay(2000);   
  lcd.print("Finding DATA");
  delay(2000);
  lcd.clear();
 


}


void loop()  
{
  t = analogRead(t1);
float mv = ( t/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;
Serial.print("TEMPERATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);


Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();


  lcd.setCursor(0,0);
lcd.print("Temperatura eshte: ");
lcd.println();
lcd.print(cel);
delay(50);
}

