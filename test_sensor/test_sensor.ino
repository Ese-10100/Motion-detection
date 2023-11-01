// #include <Arduino.h>
// #include <LiquidCrystal.h>

// #define pir_pin 6
// #define buzzer_pin 7
// #define led_pin 9

// void setup() {
//     Serial.begin(115200);
//     while (!Serial) { ; }
//     Serial.println("Ready to upload on port: COM12");

//     pinMode(pir_pin, INPUT);
//     pinMode(buzzer_pin, OUTPUT);
//     pinMode(led_pin, OUTPUT); 
// }

// void dot() {
//     tone(buzzer_pin, 1000);
//     digitalWrite(led_pin, HIGH);
//     delay(200);
//     noTone(buzzer_pin);
//     digitalWrite(led_pin, LOW);
//     delay(200);
// }

// void dash() {
//     tone(buzzer_pin, 1000);
//     digitalWrite(led_pin, HIGH);
//     delay(600);
//     noTone(buzzer_pin);
//     digitalWrite(led_pin, LOW);
//     delay(200); 
// }

// void loop() {
//   if (digitalRead(pir_pin) == HIGH) {
//       char morse_code[] = ".... . .-.. .--.";
//       int i;
//       for (i = 0; i < strlen(morse_code); i++) {
//           if (morse_code[i] == '.') {
//               dot();
//           } else if (morse_code[i] == '-') {
//               dash();
//           } else {
//               delay(400); // pause between letters
//           }
//       }
//   }
// }

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

    lcd.begin(16, 2);
    lcd.backlight();
    lcd.print("Ready");
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

void loop() {
  int pir_value = digitalRead(pir_pin);
  Serial.print("PIR value: ");
  Serial.println(pir_value);

  if (digitalRead(pir_pin) == HIGH) {
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
      Serial.print("Motion detected ");
      }
      lcd.clear();
      lcd.print("Motion detected");
  } else {
      Serial.print("No motion ");
      lcd.clear();
      lcd.print("No motion");
  }
}
