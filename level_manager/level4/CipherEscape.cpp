// CipherEscape.cpp
#include <iostream>;
#include "CipherEscape.h";
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

// The player is given the following prompt:
int CipherEscape()
{
  int count = 0;
  const int correctPasscode = 6924;
  string userInput;

  cout << "You find yourself in a small, dark room. You cannot see anything." << endl;
  cout << "You hear a voice on the loudspeaker:" << endl;
  cout << "'You must use critical thinking skills and decoders to solve the " <<;
  cout << "riddles of this room. You will have 10 minutes to escape before " <<;
  cout << "the room fills with a poisonous gas. Enter in actions, such as " <<;
  cout << "'touch', 'look', or 'use object', to interact with the room, and" <<;
  cout << "decode messages to progress. Good luck player.'" << endl;

  // The player will then have to enter a command, the corrent command here is to
  // "touch/feel the wall"

  getline (cin, userInput);
  AnswerCheck(int count, string userInput);

  // > touch/feel -> if correct count++

  count++;

  // count keeps track of what stage of the level the player is on
  // count = 1

  cout << "You reach out and feel the wall in front of you" << endl;
  cout << "You can make out distinct bumps:" << endl;
  cout << " " << endl;
  cout << ".    .    .    .  .    . .     . .  .  .      .  .    .  . ." << endl;
  cout << ".  .    .    . .    .    .          .    .  .      .  .    ." << endl;
  cout << ".       .    .         .            .  .    .         .  . ." << endl;

  // Answer: listen closely
  // Player must now enter a command once they've deciphered the message,
  // the correct command here is to "listen/listen closely"

  getline (cin, userInput);
  AnswerCheck(int count, string userInput);

  // > listen/listen closely/hear

  count++; // count = 2

  cout << "You focus your hearing. Suddenly, a faint tone can be heard beeping:" << endl;

  cout << ".-.. .. --. .... - / ... .-- .. - -.-. .... / .- -... --- ...- ." << endl;

  // Answer: light switch above
  // Player must now enter a command once they've deciphered the message,
  // the correct command here is to "touch the switch/flip the switch"

  getline (cin, userInput);
  AnswerCheck(int count, string userInput);

  // > touch switch/flip switch/reach switch/use switch

  count++; // count = 3

  cout << "You reach up high for the switch and manage to flip it on." << endl;
  cout << "A dimly lit lightbulb emits an orange glow in the room." << endl;

  getline (cin, userInput);
  AnswerCheck(int count, string userInput);

  // > look/look around/see

  count++; // count = 4

  cout << "You look around and see three sets of codes written on the wall to your " << endl;
  cout << "left, and a door with a PIN pad on the wall to your right. The codes are:" << endl;

  cout << "01100010 01100001 01110011 01100101 00110110 00110100" << endl;

  cout << "QVNDSUk=" << endl;

  cout << "83 73 88 57 84 87 79 52" << endl;

  /* Answer of Binary: Base64
    Answer of Base64: ASCII
    Answer of ASCII: SIX 9 TWO 4 */

  // Player must now enter a command once they've deciphered the messages,
  // the correct command here is to "touch the PIN pad/use the PIN pad"

  getline (cin, userInput);
  AnswerCheck(int count, string userInput);

  // > Use PIN pad/touch PIN pad/touch/feel

  cout << "You touch the PIN pad, the display turns on and message reads:" << endl;
  cout << "'Enter a 4-digit number:'" << endl;

  // Player must now enter the passcode they deciphered from the previous set of
  // messages, the correct passcode is designated as a 4-digit integer

  int passcode;
  cin >> passcode;

  while (passcode != correctPasscode) {
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Incorrect passcode." << endl;
    cout << "Please try again." << endl;
    cin >> passcode;
  }
  // > 6924

  // With the correct 4-digit passcode inputted, the player completes the level.
  // Any incorrect commands will display the message: “[user input] is not recognized as a command”.
  // For the PIN pad, the error message “Incorrect passcode” will be displayed
  cout << "You enter '6924' on the PIN pad. With a beep, the door unlocks " << endl;
  cout << "and slowly opens up. Congratulations, you've completed the level!" << endl;
  return 0;
}

void AnswerCheck(int count, string userInput)
{
  if (count == 0) {
    while (userInput != "touch" || userInput != "feel") { // loop while input is invalid
      cout << userInput << "is not recognized as a command." << endl;
      cout << "Please try again." << endl;
      cin.clear();
      cin.ignore(100,'\n');
      getline (cin, userInput);
    }
  } else if (count == 1) {
    while (userInput != "listen" || userInput != "hear") { // loop while input is invalid
      cout << userInput << "is not recognized as a command." << endl;
      cout << "Please try again." << endl;
      cin.clear();
      cin.ignore(100,'\n');
      getline (cin, userInput);
    }
  } else if (count == 2) {
    while (userInput != "use switch" || userInput != "flip switch") { // loop while input is invalid
      cout << userInput << "is not recognized as a command." << endl;
      cout << "Please try again." << endl;
      cin.clear();
      cin.ignore(100,'\n');
      getline (cin, userInput);
    }
  } else if (count == 3) {
    while (userInput != "look" || userInput != "see") { // loop while input is invalid
      cout << userInput << "is not recognized as a command." << endl;
      cout << "Please try again." << endl;
      cin.clear();
      cin.ignore(100,'\n');
      getline (cin, userInput);
    }
  } else if (count == 4) {
    while (userInput != "use PIN pad" || userInput != "touch PIN pad") { // loop while input is invalid
      cout << userInput << "is not recognized as a command." << endl;
      cout << "Please try again." << endl;
      cin.clear();
      cin.ignore(100,'\n');
      getline (cin, userInput);
    }
  }
}
