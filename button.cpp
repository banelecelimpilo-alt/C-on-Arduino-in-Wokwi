#include "Arduino.h"
#include "button.h"

Button::Button()
{
  // Setting up buttons as inputs
  for(int i = 6; i < 14; i++) pinMode(i, INPUT);
}// Button constructor

void Button::assignButtonPins(int* ledSequenceArray) {
  /*INSERT YOUR CODE BELOW*/
  Button::sequence = ledSequenceArray;
  for (int i = 0; i < 8; i++) {
      switch (ledSequenceArray[i]) {
      case 2: buttonPins[i] = 6;
          break;
      case 3: buttonPins[i] = 7;
          break;
      case 4: buttonPins[i] = 8;
          break;
      case 5: buttonPins[i] = 9;
          break;
      case A2: buttonPins[i] = 10;
          break;
      case A3: buttonPins[i] = 11;
          break;
      case A4: buttonPins[i] = 12;
          break;
      case A5: buttonPins[i] = 13;
          break;
      }
  }
}

void Button::pollButtons() {
  /*INSERT YOUR CODE BELOW*/
  if (!isCorrectButtonPressed || correctButtonsPressed >= 8) {
    return;
  }
  else {
      for (int i = 0; i < 8; i++) {
        int reading = digitalRead(buttonPins[i]);

        if (reading != lastButtonState[i]) {
          lastDebounceTime[i] = millis();
        }

        if ((millis() - lastDebounceTime[i]) > debounceDelay) {
            if (reading == HIGH && i == correctButtonsPressed) {
                digitalWrite(Button::sequence[i], HIGH);
                correctButtonsPressed++;
                delay(250);
            }
            else if (reading == HIGH && i != correctButtonsPressed) {
                isCorrectButtonPressed = false;
                return;
            }
        }

        lastButtonState[i] = reading;
      }
  }
}// pollButtons function

/*INSERT ADDITIONAL CODE BELOW IF NEED BE*/