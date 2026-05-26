#ifndef sequenceGenerator_h
#define sequenceGenerator_h

class SequenceGenerator
{
  private:
  int diode1;
  int diode2;
  int diode3;
  int diode4;
  int diode5;
  int diode6;
  int diode7;
  int diode8;

  public:

     int ledSequenceArray [8] = {2, 3, 4, 5, A2, A3, A4, A5};// array that determines the sequence of LED lighting 
  
     SequenceGenerator(int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8); // begin level sequence of lighting
     
     void pinSetup();//Set LED pins to output

     void beginLevel();//LED lighting arrangement for the beginning of a level 

     void randomiseLedSequenceArray(int &level);//randomises positions of the elements of ledSequenceArray

     void sequence();//lights LEDs in a sequence

     void resetSequence(bool &isCorrectButtonPressed);// when the user presses the wrong button, this sequence runs forever, indicating that the game is over

     void completedLevelSequence();// runs after all buttons of a level are pressed in the correct order

     void gameFinishedSequence(int &level);// loop that runs forever when all levels are completed
     
     /*You are allowed to declare and/or initialise variables and declare function prototypes as you see fit in this section*/
     
}; // end of class sequenceGenerator

#endif
