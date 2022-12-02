#!/usr/bin/python3

import os
import random
from pathlib import Path
import signal


def read_prompt_file(prompt_file: str) -> str:
    initial_prompt = ""
    prompt_file_dir: os.PathLike = None
    prompt_file_dir = Path(os.path.dirname(os.path.realpath(__file__)))
    if not Path(prompt_file_dir, prompt_file).exists():
        raise OSError(f"The file {prompt_file} couldn't be found.")
    with open(Path(prompt_file_dir, prompt_file), encoding="utf8") as fp:
        initial_prompt = fp.read()

    return initial_prompt


def run_ingame_menu():
    current_dir = os.path.dirname(os.path.realpath(__file__))
    level_manager_dir = os.path.join(current_dir, '..')
    ingame_menu_filename = 'inGameMenu.sh'
    ingame_menu_path = os.path.join(level_manager_dir, ingame_menu_filename)

    subprocess.run(ingame_menu_path)


def mainloop():
    global guess, retries
    # continue looping until an answer is satisfactory or the user runs out of retries
    while retries >= 1 and guess != blocks_set.height:
        guess = input(f"Enter your guess. You have {retries} tries left. Enter (H) for help and (M) for the ingame menu:\n").strip()
        
        # user input other than guesses
        if guess.lower() == 'h':
            print("""The goal of the game is to stack the blocks in pairs of 2 so that they create a wall of uniform height.
                     The wall is used to block the acid. For example, if you had one block of height 2, and another of
                     height 3, you could combine them to make a stack of height 5.""")
        elif guess.lower() == 'm':
            run_ingame_menu()
        else:
            try:
                old_guess = guess
                guess = int(guess)
            except ValueError:
                guess = old_guess

            if guess == blocks_set.height:
                print(f"Congratulations! Your guess of {guess} was correct!")
                blocks_set.print_completed_wall()
                print("You build a wall and it successfully blocks the acid.")
            else:
                print(f"{guess} is not correct.")
                retries -= 1

    if retries == 0 and guess != blocks_set.height:
        print(f"The correct answer was {blocks_set.height}")
        input("Press enter to continue")
        exit(0)

    input("Press enter to continue")
    exit(1)


def out_of_time_exit(sig_num, stack_frame):
    print("The game ended because you ran out of time")
    exit(0)


class BlockSet:
    def __init__(self):
        self.blocks = []
        # the answer for how the blocks should be stacked
        self.answer = -1
        self.height = -1

    def generate_blocks(self, width: int, min_height: int, max_height: int):
        self.height = random.randint(min_height+1, max_height)

        for i in range(width):
            first_block = self.height - random.randint(min_height, self.height-1)
            second_block = self.height-first_block
            self.blocks.append(first_block)
            self.blocks.append(second_block)

        random.shuffle(self.blocks)

    def print_blocks(self):
        output = ""

        max_height = max(self.blocks)
        for current_level in range(max_height+1):
            
            for block_height in self.blocks:
                if current_level < max_height:
                    if max_height-current_level <= block_height:
                        output += '##'
                    else:
                        output += '  '
                else:
                    output += f"{block_height:<2}"
                output += '  '
            output += '\n'

        print(output)

    def print_completed_wall(self):
        output = ''
        for current_level in range(self.height):
            for i in range(len(self.blocks)):
                output += '##'
                if i < len(self.blocks)-1:
                    output += ' '
            output += '\n'

        print(output)


if __name__ == '__main__':
    # setup the game
    timeout = 300  # exit the game after the timeout is exceeded (in seconds)
    retries = 3
    guess = None
    
    min_height, max_height, width = random.randint(5, 10), random.randint(10, 20), random.randint(3, 10)
    blocks_set = BlockSet()
    blocks_set.generate_blocks(width, min_height, max_height)

    # give initial prompt
    initial_prompt = read_prompt_file('initial_prompt.txt')
    
    print(initial_prompt)
    print("You arrange the blocks and find that they have the following heights:\n")
    blocks_set.print_blocks()
    print("How high must you stack the blocks?")

    signal.signal(signal.SIGALRM, out_of_time_exit)
    signal.alarm(timeout)

    mainloop()
