// CipherEscape.cpp
#include <iostream>
#include "cipher_escape.h"
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

// Usable commands
const string touch = "touch";
const string listen = "listen";
const string useSwitch = "useSwitch";
const string look = "look";
const string usePINpad = "usePINpad";

const int correctPasscode = 6924;

int main()
{
  // Opening message to player
  cout << "You find yourself in a small, dark room. You cannot see anything." << endl;
  cout << "You hear a voice on the loudspeaker:" << endl;
  cout << "'You must use critical thinking skills and decoders to solve the ";
  cout << "riddles of this room. You will have 10 minutes to escape " << endl;
  cout << "before the room fills with a poisonous gas. Enter in single word actions, ";
  cout << "such as 'touch', 'look', or 'useObject', to interact with the room, ";
  cout << "and decode messages to progress. If nothing happens when ";
  cout << "you input a command, try something different. " << endl;
  cout << "Good luck player. Now, begin.'" << endl;
  cout << " " << endl;

  // The player will then have to enter a command

  int count = 0;
  string userInput;

  cin >> userInput;
  AnswerCheck(count, userInput);

  // > touch -> if correct count++
  // count keeps track of what stage of the level the player is on

  cout << " " << endl;
  cout << "You reach out and touch the cold, stone wall in front of you." << endl;
  cout << "You can make out several distinct bumps:" << endl;
  cout << " " << endl;
  cout << ".    .    .    .  .    . .     . .  .  .      .  .    .  . ." << endl;
  cout << ".  .    .    . .    .    .          .    .  .      .  .    ." << endl;
  cout << ".       .    .         .            .  .    .         .  . ." << endl;
  cout << " " << endl;

  count++; // count = 1

  // Answer: listen closely
  // Player must enter a command once they've deciphered the message

  cin >> userInput;
  AnswerCheck(count, userInput);

  // > listen

  cout << " " << endl;
  cout << "You focus your hearing. Suddenly, a faint tone can be heard beeping:" << endl;
  cout << " " << endl;
  cout << ".-.. .. --. .... - / ... .-- .. - -.-. .... / .- -... --- ...- ." << endl;
  cout << " " << endl;

  // Answer: light switch above

  count++; // count = 2

  cin >> userInput;
  AnswerCheck(count, userInput);

  // > useSwitch

  cout << " " << endl;
  cout << "You reach up high for the switch and manage to flip it on." << endl;
  cout << "A dimly lit lightbulb emits an orange glow in the room." << endl;
  cout << " " << endl;

  count++; // count = 3

  cin >> userInput;
  AnswerCheck(count, userInput);

  // > look

  cout << " " << endl;
  cout << "You look around and see a metal door with a PINpad on the wall to your right," << endl;
  cout << "and three sets of codes carved into the wall to your left:" << endl;
  cout << " " << endl;
  cout << "01100010 01100001 01110011 01100101 00110110 00110100" << endl;
  cout << " " << endl;
  cout << "QVNDSUk=" << endl;
  cout << " " << endl;
  cout << "83 73 88 57 84 87 79 52" << endl;
  cout << " " << endl;

  /* Answer of Binary: Base64
     Answer of Base64: ASCII
     Answer of ASCII: SIX 9 TWO 4 */

  count++; // count = 4

  cin >> userInput;
  AnswerCheck(count, userInput);

  // > usePINpad

  cout << " " << endl;
  cout << "You use the PINpad. The display turns on and a message reads:" << endl;
  cout << "'Enter a 4-digit number:'" << endl;
  cout << " " << endl;

  // Player must now enter the passcode they deciphered from the previous set of
  // messages, the correct passcode is designated as a 4-digit integer

  int passcode;
  cin >> passcode;

  while(passcode != correctPasscode) {
    cin.clear();
    cin.ignore(100,'\n');
    cout << " " << endl;
    cout << "Incorrect passcode." << endl;
    cout << "Please try again." << endl;
    cout << " " << endl;
    cin >> passcode;
  }
  // > 6924

  // With the correct 4-digit passcode inputted, the player completes the level.
  // Any incorrect commands will display the message: “[user input] is not recognized as a command”.
  // For the PIN pad, the error message “Incorrect passcode.” will be displayed

  cout << " " << endl;
  cout << "You enter " << correctPasscode << " on the PIN pad. With a beep, the door unlocks " << endl;
  cout << "and slowly swings open. Freedom. Congratulations, you've completed the level!" << endl;
  cout << " " << endl;

  return 0;
}

void AnswerCheck(int count, string userInput)
{
  if(count == 0) {
    while(userInput != touch) { // loop while input is invalid
      cout << " " << endl;
      cout << "Nothing happens." << endl;
      cout << " " << endl;
      cin.clear();
      cin.ignore(100,'\n');
      cin >> userInput;
    }
  } else if(count == 1) {
    while(userInput != listen) { // loop while input is invalid
      cout << " " << endl;
      cout << "Nothing happens." << endl;
      cout << " " << endl;
      cin.clear();
      cin.ignore(100,'\n');
      cin >> userInput;
    }
  } else if(count == 2) {
    while(userInput != useSwitch) { // loop while input is invalid
      cout << " " << endl;
      cout << "Nothing happens." << endl;
      cout << " " << endl;
      cin.clear();
      cin.ignore(100,'\n');
      cin >> userInput;
    }
  } else if(count == 3) {
    while(userInput != look) { // loop while input is invalid
      cout << " " << endl;
      cout << "Nothing happens." << endl;
      cout << " " << endl;
      cin.clear();
      cin.ignore(100,'\n');
      cin >> userInput;
    }
  } else if (count == 4) {
    while (userInput != usePINpad) { // loop while input is invalid
    cout << " " << endl;
    cout << "Something happens, it was nothing." << endl;
    cout << " " << endl;
      cin.clear();
      cin.ignore(100,'\n');
      cin >> userInput;
    }
  }
  return;
}
