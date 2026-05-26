#ifndef button_h
#define button_h

class Button
{
  private:
    int buttonPins [8] = {6, 7, 8, 9, 10, 11, 12, 13};//Array that represents pins connected to buttons for reading
    int* sequence;
    unsigned long lastDebounceTime[8] = {0};
    bool lastButtonState[8] = {0};
    const unsigned long debounceDelay = 50;
/* You are allowed to declare and/or initialise variables and declare function prototypes here (use as many lines as you need) */

  public:
    // Constructor
    Button();

    /*THIS VARIABLE MUST BE USED IN YOUR CODE*/
    bool isCorrectButtonPressed = true;// Initially true until wrong button is pressed 

     /*THIS VARIABLE MUST BE USED IN YOUR CODE*/ 
    int correctButtonsPressed = 0;// used to check how many buttons have been pressed in the correct order

    void assignButtonPins(int* ledSequenceArray);// takes in ledSequenceArray and maps associated members in buttonPins array 

    void pollButtons();// Checks if any buttons have gone high and if the buttons are being pressed in the correct order.  Also handles button debouncing

    /* You are allowed to declare variables and functions as you see fit  in this section (use as many lines as you need) */
}; // end of class sequenceGenerator

#endif
