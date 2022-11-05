#!/usr/bin/env python3

import random


class BlockSet:
    def __init__(self):
        self.blocks = []
        # the answer for how the blocks should be stacked
        self.answer = -1
        self.height = -1

    def generate_blocks(self, width: int, min: int, max: int):
        self.height = random.randint(min, max)

        for i in range(width):
            first_block = self.height - random.randint(min+1, max-1)
            second_block = self.height-first_block
            self.blocks.append(first_block)
            self.blocks.append(second_block)


def test_answer(answer: int, blocks: list) -> bool:
    """Return whether or not the given height can be used to stack the blocks into pairs of two

    Args:
        answer (int): _description_
        blocks (list): _description_

    Returns:
        bool: _description_
    """
    pass


if __name__ == '__main__':
    # setup the game
    retries = 3
    min_height, max_height, width = random.randint(5, 10), random.randint(10, 20), random.randint(5, 20)
    
    # give initial prompt
    blocks_set = BlockSet()
    blocks_set.generate_blocks(width, min_height, max_height)
    guess = None
    print("Welcome to the puzzle.")
    print(f"The heights are {blocks_set.blocks}")

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
