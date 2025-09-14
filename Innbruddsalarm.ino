#define PIN_PIRSENSOR 2 //Pin nummeret for PIR-sensor
#define PIN_LED 8 //Pin nummeret for LED
#include <LiquidCrystal_I2C.h>
int buzz = 6; //Pin nummeret for buzzer

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 16 columns and 2 rows


void setup() {
  Serial.begin(9600); // start serial connection to print out messages to the serial monitor
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on the LCD backlight
  pinMode(PIN_PIRSENSOR, INPUT); // Putter PIR-sensor som INPUT
  pinMode(buzz, OUTPUT); // Putter buzzer som OUTPUT
  pinMode(PIN_LED, OUTPUT); // Putter LED som OUTPUT
  digitalWrite(PIN_LED, LOW); // Putter LED i LOW/0
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);  // Set cursor to the first column and row 
  int movement_detected = digitalRead(PIN_PIRSENSOR);  //Leser digitalt fra PIR-sensoren
  if (movement_detected) {
    // Hvis bevegelse blir oppdaget av PIR-sensoren
    lcd.print("Movement detected.");
    Serial.println("Movement detected."); //Printer i Serial Monitor
    digitalWrite(PIN_LED, HIGH); // LED-en lyser
    tone(buzz, 200); //Buzz lager lyd med 200Hz
    delay(600); // Venter/lager lyd i 0,24 sekund
    tone(buzz, 340); //Buzz lager lyd med 100Hz
    delay(600); // Venter/lager lyd i 0,24 sekund
  } else {
    digitalWrite(PIN_LED, LOW); // LED-en lyser ikke
    noTone(buzz); //Buzzer lager ikke lyd
    lcd.print("Movement not detected.");
    Serial.println("Movement not detected."); //Printer i Serial Monitor
  }


}








