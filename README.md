Repeat The Sequence – Arduino Memory Game

## About The Project
Repeat The Sequence is a memory-based mini-game developed using an Arduino Uno and programmed in C++ within the Wokwi simulation environment.

The project was completed as part of an academic practical assignment for Computer Methods 3 (ENEL3CCH1) at the University of KwaZulu-Natal School of Engineering.

The objective of the project was to apply object-oriented programming principles in an embedded systems environment while working with:
- LEDs
- Pushbuttons
- Arrays
- Randomisation
- Input/output control
- Software debouncing

The final system simulates a memory game where the player must correctly repeat LED sequences using corresponding pushbuttons.

---

# How The Game Works
The game consists of:
- 8 LEDs
- 8 Pushbuttons
- Arduino Uno

Each LED is associated with a specific pushbutton.

At the beginning of a level:
1. The LEDs flash in a particular sequence.
2. The player memorises the sequence.
3. The player repeats the sequence by pressing the correct buttons in order.
4. When a button is pressed, its associated LED lights up as feedback.

If the player enters the correct sequence:
- the level is completed
- a success indication is shown
- the next level begins

If the player presses the wrong button:
- the level resets
- an incorrect sequence indication is displayed
