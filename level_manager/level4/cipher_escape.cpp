// CipherEscape.cpp
#include <iostream>
#include <fstream>
#include "cipher_escape.h"
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

// Usable commands
const string touch = "touch";
const string listen = "listen";
const string useSwitch = "uselightswitch";
const string look = "look";
const string usePINpad = "usepinpad";
const string decodeCMD = "d";

const int correctPasscode = 692420;
const int ignoreVal = 100;
const int maxIncorrectANS = 20;

// Global variable to update throughout functions
int incorrectANS = 0;
int main()
{
  // Opening message to player
  cout << " " << endl;
  cout << "You find yourself in a small, dark room." << endl;
  cout << "You hear a voice on the loudspeaker:" << endl;
  cout << "'You must use critical thinking skills and the decoder to solve the" << endl;
  cout << "riddles of this room. Enter in single string actions, with syntax such as 'touch'," << endl;
  cout << "'look', and for objects 'useobjectlikethis' to interact with the room. Decode messages" << endl;
  cout << "to progress. If nothing happens when you input a command, try something" << endl;
  cout << "different. Enter 'D' to open the decoder. If you enter an incorrect" << endl;
  cout << "action a total of 20 times, the room will fill with a poisonous gas." << endl;
  cout << "Good luck player. Now, begin.'" << endl;
  cout << " " << endl;
  cout << "The room is cold and devoid of any light. Maybe you should feel " << endl;
  cout << "around and 'touch' the walls..." << endl;
  cout << " " << endl;

  string userInput;
  bool correct;

  do {

    cin >> userInput; // The player will then have to enter a command
    correct = StageOneCheck(userInput);

    if (incorrectANS == maxIncorrectANS) {
      cout << " " << endl;
      cout << "Max incorrect answers reached. Level failed..." << endl;
      cout << " " << endl;
      return 0;
    }

  } while (correct == false);

  // > touch

  cout << " " << endl;
  cout << "You reach out and touch the cold, stone wall in front of you." << endl;
  cout << "You can make out several distinct bumps:" << endl;
  cout << " " << endl;
  cout << ".    .    .    .  .    . .     . .  .  .      .  .    .  . ." << endl;
  cout << ".  .    .    . .    .    .          .    .  .      .  .    ." << endl;
  cout << ".       .    .         .            .  .    .         .  . ." << endl;
  cout << " " << endl;

  // Answer: listen closely
  // Player must enter a command once they've deciphered the message

  do {

    cin >> userInput; // The player will then have to enter a command
    correct = StageTwoCheck(userInput);

    if (incorrectANS == maxIncorrectANS) {
      cout << " " << endl;
      cout << "Max incorrect answers reached. Level failed..." << endl;
      cout << " " << endl;
      return 0;
    }

  } while (correct == false);

  // > listen

  cout << " " << endl;
  cout << "You focus your hearing. Suddenly, a faint tone can be heard beeping:" << endl;
  cout << " " << endl;
  cout << "..- ... . / .-.. .. --. .... - / ... .-- .. - -.-. ...." << endl;
  cout << " " << endl;

  // Answer: use light switch

  do {

    cin >> userInput; // The player will then have to enter a command
    correct = StageThreeCheck(userInput);

    if (incorrectANS == maxIncorrectANS) {
      cout << " " << endl;
      cout << "Max incorrect answers reached. Level failed..." << endl;
      cout << " " << endl;
      return 0;
    }

  } while (correct == false);

  // > useLightSwitch

  cout << " " << endl;
  cout << "You reach up high for the switch and manage to flip it on." << endl;
  cout << "A dimly lit lightbulb emits an orange glow in the room." << endl;
  cout << "You can now 'look' around." << endl;
  cout << " " << endl;

  do {

    cin >> userInput; // The player will then have to enter a command
    correct = StageFourCheck(userInput);

    if (incorrectANS == maxIncorrectANS) {
      cout << " " << endl;
      cout << "Max incorrect answers reached. Level failed..." << endl;
      cout << " " << endl;
      return 0;
    }


  } while (correct == false);

  // > look

  cout << " " << endl;
  cout << "You look around and see a metal door with a 'usable PINpad' on the wall to your right," << endl;
  cout << "and four sets of codes carved into the wall to your left:" << endl;
  cout << " " << endl;
  cout << "01010011 01001001 01011000 / ";
  cout << "01000001 01010100 01000010 01000001 01010011 01001000" << endl;
  cout << " " << endl;
  cout << "MRMV GDL / ZHXRR" << endl;
  cout << " " << endl;
  cout << "70 79 85 82 / 75 69 89 66 79 65 82 68" << endl;
  cout << " " << endl;
  cout << "ZVG MTKG" << endl;
  cout << " " << endl;

  /* Answer of Binary: SIX / ATBASH
     Answer of Atbash: NINE TWO / ASCII
     Answer of ASCII: FOUR / KEYBOARD
     Answer of Keyboard: TWO ZERO
     PASSCODE: 692420                */

  do {

    cin >> userInput; // The player will then have to enter a command
    correct = StageFiveCheck(userInput);

    if (incorrectANS == maxIncorrectANS) {
      cout << " " << endl;
      cout << "Max incorrect answers reached. Level failed..." << endl;
      cout << " " << endl;
      return 0;
    }
  } while (correct == false);

  // > usePINpad

  cout << " " << endl;
  cout << "You use the PINpad. The display turns on and a message reads:" << endl;
  cout << "'Enter a 6-digit number:'" << endl;
  cout << " " << endl;

  // Player must now enter the passcode they deciphered from the previous set of
  // messages, the correct passcode is designated as a 4-digit integer

  int passcode;
  cin >> passcode;

  while(passcode != correctPasscode) {
    cin.clear();
    cin.ignore(ignoreVal,'\n');
    cout << " " << endl;
    cout << "Incorrect passcode." << endl;
    cout << "Please try again." << endl;
    cout << " " << endl;
    cin >> passcode;
  }
  // > 692420

  // With the correct 6-digit passcode inputted, the player completes the level
  // Any incorrect commands will display the message: “Nothing happens.”
  // For the PIN pad, the error message “Incorrect passcode.” will be displayed

  cout << " " << endl;
  cout << "You enter " << correctPasscode << " on the PIN pad. With a beep, the door unlocks " << endl;
  cout << "and slowly swings open. Freedom. Congratulations, you've completed the level!" << endl;
  cout << " " << endl;
  cout << "Enter any key to continue." << endl;
  cout << " " << endl;
  cin >> userInput;

  return 1;
}

// Takes count & user's input as variables and checks if the player was correct
bool StageOneCheck(string userInput)
{
  if(userInput == touch) {

    return true;

  } else if(userInput == decodeCMD) {

    DisplayDecoder(); // call display function
    return false;

  } else {

    cout << " " << endl;
    cout << "Nothing happens." << endl;
    cout << " " << endl;
    incorrectANS++;
    return false;
  }
}

// Takes count & user's input as variables and checks if the player was correct
bool StageTwoCheck(string userInput)
{
  if(userInput == listen) {

    return true;

  } else if(userInput == decodeCMD) {

    DisplayDecoder(); // call display function
    return false;

  } else {

    cout << " " << endl;
    cout << "Nothing happens." << endl;
    cout << " " << endl;
    incorrectANS++;
    return false;
  }
}

// Takes count & user's input as variables and checks if the player was correct
bool StageThreeCheck(string userInput)
{

  if(userInput == useSwitch) {

    return true;

  } else if(userInput == decodeCMD) {

    DisplayDecoder(); // call display function
    return false;

  } else {

    cout << " " << endl;
    cout << "Nothing happens." << endl;
    cout << " " << endl;
    incorrectANS++;
    return false;
  }
}

// Takes count & user's input as variables and checks if the player was correct
bool StageFourCheck(string userInput)
{
  if(userInput == look) {

    return true;

  } else if(userInput == decodeCMD) {

    DisplayDecoder(); // call display function
    return false;

  } else {

    cout << " " << endl;
    cout << "Nothing happens." << endl;
    cout << " " << endl;
    incorrectANS++;
    return false;
  }
}

// Takes count & user's input as variables and checks if the player was correct
bool StageFiveCheck(string userInput)
{
  if(userInput == usePINpad) {

    return true;

  } else if(userInput == decodeCMD) {

    DisplayDecoder(); // call display function
    return false;

  } else {

    cout << " " << endl;
    cout << "Nothing happens." << endl;
    cout << " " << endl;
    incorrectANS++;
    return false;
  }
}

void DisplayDecoder()
{
  string textLines;
  std::ifstream decodeFile("Codes_CipherEscape.txt");

  if(decodeFile.is_open()) {
    while(getline(decodeFile, textLines)) {
      cout << textLines << endl;
    }
      decodeFile.close();
    } else {
      cout << "Error: File not opened." << endl;
    }
  cout << " " << endl;
}
