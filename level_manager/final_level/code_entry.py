#!/usr/bin/python3

import os
import subprocess


def read_data_file(file_name):
    data = ""
    prompt_file_dir = None
    prompt_file_dir = os.path.dirname(os.path.realpath(__file__))
    if not os.path.exists(os.path.join(prompt_file_dir, file_name)):
        raise OSError("The file {} couldn't be found.".format(file_name))
    with open(os.path.join(prompt_file_dir, file_name), 'rb') as fp:
        data = fp.read().decode('UTF-8')

    return data


def run_ingame_menu():
    current_dir = os.path.dirname(os.path.realpath(__file__))
    level_manager_dir = os.path.join(current_dir, '..')
    ingame_menu_filename = 'inGameMenu.sh'
    ingame_menu_path = os.path.join(level_manager_dir, ingame_menu_filename)

    subprocess.run(ingame_menu_path)


if __name__ == '__main__':
    ### setup the game
    retries = 3
    guess = None
    initial_prompt = read_data_file('initial_prompt.txt')

    # read the file containing the code
    code = read_data_file('../final_code.txt').strip()
    assert code  # some code should have been populated. otherwise an error should occur

    ### give the initial prompt
    print(initial_prompt)

    # continue looping until an answer is satisfactory or the user runs out of retries
    while retries >= 1 and not guess == code:
        guess = input("Enter your guess or perform some other action: (H) for help and (M) for the ingame menu."
                      " You have {} tries left:\n".format(retries)).strip()

        # user input other than guesses
        if guess.lower() == 'h':
            print(initial_prompt)
        elif guess.lower() == 'm':
            run_ingame_menu()
        else:
            try:
                old_guess = guess
                guess = str(guess)
            except ValueError:
                guess = old_guess

            if guess == code:
                print("Congratulations! Your guess of {} was correct!".format(guess))
            elif guess:
                print("{} is not correct.".format(guess))
                retries -= 1

    if retries == 0 and not guess == code:
        print("A correct answer was {}".format(code))
        input("Press enter to continue")
        exit(0)

    input("Press enter to continue")
    exit(1)
