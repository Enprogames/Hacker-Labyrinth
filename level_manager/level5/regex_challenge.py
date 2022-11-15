#!/usr/bin/python3

import os
import re
import json
import random
from pathlib import Path


def read_data_file(file_name: str) -> str:
    data = ""
    prompt_file_dir: os.PathLike = None
    prompt_file_dir = Path(os.path.dirname(os.path.realpath(__file__)))
    if not Path(prompt_file_dir, file_name).exists():
        raise OSError(f"The file {file_name} couldn't be found.")
    with open(Path(prompt_file_dir, file_name), encoding="utf8") as fp:
        data = fp.read()

    return data


class RegexTestSet:
    def __init__(self, name: str, valid_strings: list[str] = [],
                 invalid_strings: list[str] = []):
        self.name: str = name
        self.valid_strings: list[str] = valid_strings
        self.invalid_strings: list[str] = invalid_strings

    def test_pattern(self, pattern: str):

        valid_passes = False
        invalid_passes = False
        if pattern:
            try:
                regex = re.compile(pattern)
                for test_str in self.valid_strings:
                    if not regex.match(test_str):
                        valid_passes = False
                        break
                else:
                    valid_passes = True

                for test_str in self.invalid_strings:
                    if regex.match(test_str):
                        invalid_passes = False
                        break
                else:
                    invalid_passes = True
            except TypeError:
                pass

        return valid_passes and invalid_passes


if __name__ == '__main__':
    # setup the game
    retries = 3
    guess = None
    initial_prompt = read_data_file('initial_prompt.txt')

    regex_patterns = json.loads(read_data_file('regex_types.json'))
    pattern_data = random.choice(list(regex_patterns.items()))
    name: str = pattern_data[0]
    valid_pattern = pattern_data[1]['valid']
    valid_strs: list[str] = pattern_data[1]['valid_strs']
    invalid_strs: list[str] = pattern_data[1]['invalid_strs']

    # randomly select a pattern object
    pattern_set = RegexTestSet(name, valid_strs, invalid_strs)

    # give initial prompt
    print(initial_prompt)
    print(f"Give a regular expression to match {name.lower()}s")
    print(f"Examples of valid {name.lower()}s:")
    for valid_str in pattern_set.valid_strings:
        print(valid_str)
    
    print(f"Examples of invalid {name.lower()}s:")
    for invalid_str in pattern_set.invalid_strings:
        print(invalid_str)
    

    # continue looping until an answer is satisfactory or the user runs out of retries
    while retries >= 1 and not pattern_set.test_pattern(guess):
        guess = input(f"Enter your guess. You have {retries} tries left:\n")
        try:
            old_guess = guess
            guess = str(guess)
        except ValueError:
            guess = old_guess

        if pattern_set.test_pattern(guess):
            print(f"Congratulations! Your guess of {guess} was correct!")
        else:
            print(f"{guess} is not correct.")
            retries -= 1
    
    if retries == 0 and not pattern_set.test_pattern(guess):
        print(f"A correct answer was {valid_pattern}")
