#include <Arduino.h>
int previous_state = HIGH;
int button_state;
int counter = 0;

#define power 10
#define off 9
#define button 12

void setup() {

  pinMode(power, OUTPUT);
  pinMode(off, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(off, LOW);
}

void loop() {
  button_state = digitalRead(button);

 if (button_state == LOW && previous_state == HIGH) {
    delay(20);

    if (digitalRead(button) == LOW) {
        counter++;
        Serial.println(counter);

        while (digitalRead(button) == LOW) {
            // wait for actual release
        }

        delay(20);
    }
}
  previous_state = button_state;

  if (counter == 1) {
    analogWrite(power, 64);
  }
  else if (counter == 2) {
    analogWrite(power, 127);
  }
  else if (counter == 3){
    analogWrite(power, 191);
  }
  else if (counter == 4){
    analogWrite(power, 255);
  }
  else if (counter > 4){
    analogWrite(power, 0);
    counter = 0;
  }
  else{
    analogWrite(power, 0);
  }
}

