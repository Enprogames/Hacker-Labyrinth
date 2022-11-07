#!/usr/bin/env python3

import os
import random
from pathlib import Path


class BlockSet:
    def __init__(self):
        self.blocks = []
        # the answer for how the blocks should be stacked
        self.answer = -1
        self.height = -1

    def generate_blocks(self, width: int, min: int, max: int):
        self.height = random.randint(min, max)

        for i in range(width):
            first_block = self.height - random.randint(1, self.height-1)
            second_block = self.height-first_block
            self.blocks.append(first_block)
            self.blocks.append(second_block)

        random.shuffle(self.blocks)


def read_prompt_file(prompt_file: str) -> str:
    initial_prompt = ""
    prompt_file_dir: os.PathLike = None
    if Path('level_manager', 'level1', prompt_file).exists():
        prompt_file_dir = Path('level_manager', 'level1')
    elif Path('level1', prompt_file).exists():
        prompt_file_dir = Path('level1')
    elif Path('', prompt_file).exists():
        prompt_file_dir = Path('', prompt_file)
    else:
        raise OSError(f"The file {prompt_file} couldn't be found.")
    with open(Path(prompt_file_dir, prompt_file), encoding="utf8") as fp:
        initial_prompt = fp.read()

    return initial_prompt


if __name__ == '__main__':
    # setup the game
    retries = 3
    min_height, max_height, width = random.randint(5, 10), random.randint(10, 20), random.randint(5, 20)
    
    blocks_set = BlockSet()
    blocks_set.generate_blocks(width, min_height, max_height)
    guess = None

    # give initial prompt
    initial_prompt = read_prompt_file('initial_prompt.txt')
    
    print(initial_prompt)
    print(f"You arrange the blocks and find that they have the following heights:\n{blocks_set.blocks}")
    print("How high must you stack the blocks?")

    # if 
    while retries >= 1 and guess != blocks_set.height:
        guess = input(f"Enter your guess. You have {retries} tries left:\n")
        try:
            old_guess = guess
            guess = int(guess)
        except ValueError:
            guess = old_guess

        if guess == blocks_set.height:
            print(f"Congratulations! Your guess of {guess} was correct!")
        else:
            print(f"{guess} is not correct.")
            retries -= 1
    
    if retries == 0 and guess != blocks_set.height:
        print(f"The correct answer was {blocks_set.height}")
