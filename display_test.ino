#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pir_pin 6
#define buzzer_pin 7
#define led_pin 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    while (!Serial) { ; }
    Serial.println("Ready to upload on port: COM12");

    pinMode(pir_pin, INPUT);
    pinMode(buzzer_pin, OUTPUT);
    pinMode(led_pin, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.print("Ready");
    Serial.println("LCD SET!");
}

void dot() {
    tone(buzzer_pin, 1000);
    digitalWrite(led_pin, HIGH);
    delay(200);
    noTone(buzzer_pin);
    digitalWrite(led_pin, LOW);
    delay(200);
    Serial.println("DOT");
}

void dash() {
    tone(buzzer_pin, 1000);
    digitalWrite(led_pin, HIGH);
    delay(600);
    noTone(buzzer_pin);
    digitalWrite(led_pin, LOW);
    delay(200); 
    Serial.println("DASH");
}
void x162LCD()
{
  if (digitalRead(pir_pin) == HIGH)
{
Serial.println("HIGH");
lcd.clear();
lcd.print("Motion detected");
}
else{
  Serial.println("LOW");
  lcd.clear();
  lcd.print("No motion");
}
}

void loop() {
  int pir_value = digitalRead(pir_pin);
  Serial.print("PIR value: ");
  Serial.println(pir_value);

  if (digitalRead(pir_pin) == HIGH) {
     Serial.println("HIGH");
     delay(500);
      char morse_code[] = ".... . .-.. .--.";
      int i;
      for (i = 0; i < strlen(morse_code); i++) {
          Serial.print("Current Character: ");
          Serial.println(morse_code[i]);
          if (morse_code[i] == '.') {
              dot();
          } else if (morse_code[i] == '-') {
              dash();
          } else {
              delay(400); // pause between letters
          }
      }
      x162LCD();     
  }
}
// #include <Wire.h>
// #include <hd44780.h>
// #include <hd44780ioClass/hd44780_I2Cexp.h>

// hd44780_I2Cexp lcd;

// void setup()
// {
//   int status;
//   status = lcd.begin(16, 2);
//   if(status)
//   {
//     hd44780::fatalError(status);
//     Serial.print("Failed");
//   }
//   lcd.print("Ready");
// }

// void loop()
// {
// }


// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// #define pir_pin 6
// #define buzzer_pin 7
// #define led_pin 9
// #define lcd_test_pin 10 // define the LCD test pin

// LiquidCrystal_I2C lcd(0x27, 16, 2);
// bool lcdConnected = false; // initialize the boolean variable to store the LCD connection status

// void setup() {
//     Serial.begin(115200);
//     while (!Serial) { ; }
//     Serial.println("Ready to upload on port: COM12");

//     pinMode(pir_pin, INPUT);
//     pinMode(buzzer_pin, OUTPUT);
//     pinMode(led_pin, OUTPUT);
//     pinMode(lcd_test_pin, INPUT_PULLUP); // set the LCD test pin as input with internal pull-up resistor

//     if (digitalRead(lcd_test_pin) == LOW) { // check if the LCD test pin is connected to ground
//         lcdConnected = true; // set the LCD connection status to true
//         lcd.begin(16, 2);
//         lcd.backlight();
//         lcd.print("Ready");
//     }
// }

// void dot() {
//     tone(buzzer_pin, 1000);
//     digitalWrite(led_pin, HIGH);
//     delay(200);
//     noTone(buzzer_pin);
//     digitalWrite(led_pin, LOW);
//     delay(200);
//     Serial.println("DOT");
// }

// void dash() {
//     tone(buzzer_pin, 1000);
//     digitalWrite(led_pin, HIGH);
//     delay(600);
//     noTone(buzzer_pin);
//     digitalWrite(led_pin, LOW);
//     delay(200); 
//     Serial.println("DASH");
// }

// void loop() {
//   int pir_value = digitalRead(pir_pin);
//   Serial.print("PIR value: ");
//   Serial.println(pir_value);

//   if (digitalRead(pir_pin) == HIGH) {
//       char morse_code[] = ".... . .-.. .--.";
//       int i;
//       for (i = 0; i < strlen(morse_code); i++) {
//           Serial.print("Current Character: ");
//           Serial.println(morse_code[i]);
//           if (morse_code[i] == '.') {
//               dot();
//           } else if (morse_code[i] == '-') {
//               dash();
//           } else {
//               delay(400); // pause between letters
//           }
//       }
//       if (lcdConnected) { // check if the LCD is connected
//           lcd.clear();
//           lcd.print("Motion detected");
//       }
//   } else {
//       if (lcdConnected) { // check if the LCD is connected
//           lcd.clear();
//           lcd.print("No motion");
//       }
//   }
// }