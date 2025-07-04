# EVM_Module_using_TinkerCAD
This project is a microcontroller-based Electronic Voting Machine (EVM) built using an Arduino Uno and an I2C LCD display.
It allows voting for four candidates and displays the voting results, indicating the winner or if there’s a tie.

**Hardware Components :-**

1.Arduino Uno board

2.I2C-based 16×2 LCD

3.Five push-buttons:

Four buttons for voting (BJP, INC, AAP, OTH)

One button for displaying results

4.Two LEDs:

Green LED (vote confirmation)

Red LED (result process indicator)

5.Resistors

6.Breadboard and connecting wires

**Working Process:-**
When a voter presses any voting button:

The corresponding vote count increases by 1.

The green LED (pin 12) turns ON for 500 ms to confirm the vote.

LCD updates the vote count under the party’s name.

A small delay ensures the button is released before accepting further input.

**Displaying Results**
Pressing the Result button (pin 7):

Turns ON the red LED (pin 13) to indicate result mode.

Checks which party has the highest votes.

After displaying the result:

All vote counts reset to zero.

Both LEDs turn OFF, ready for a new round of voting.

**Error Handling**
The code handles situations like:

No votes cast at all → displays “No Voting…”

Equal highest votes (tie) → displays “Tie Up Or No Result”

**Software Notes**
Uses the Adafruit LiquidCrystal library for the I2C LCD.
n summary, this EVM project allows users to vote for four parties using push-buttons, tracks votes live on an LCD, and displays results indicating the winner or tie, while using LEDs for visual confirmation.
