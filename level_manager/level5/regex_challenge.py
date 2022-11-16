#!/usr/bin/python3

import os
import re
import json
import random


def read_data_file(file_name):
    data = ""
    prompt_file_dir = None
    prompt_file_dir = os.path.dirname(os.path.realpath(__file__))
    if not os.path.exists(os.path.join(prompt_file_dir, file_name)):
        raise OSError("The file {} couldn't be found.".format(file_name))
    with open(os.path.join(prompt_file_dir, file_name), 'rb') as fp:
        data = fp.read().decode('UTF-8')

    return data


class RegexTestSet:
    def __init__(self, name, valid_strings=[],
                 invalid_strings=[]):
        self.name = name
        self.valid_strings = valid_strings
        self.invalid_strings = invalid_strings

    def test_pattern(self, pattern):

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
            except (TypeError, re.error):
                pass

        return valid_passes and invalid_passes


if __name__ == '__main__':
    # setup the game
    retries = 3
    guess = None
    initial_prompt = read_data_file('initial_prompt.txt')

    regex_patterns = json.loads(read_data_file('regex_types.json'))
    pattern_data = random.choice(list(regex_patterns.items()))
    name = pattern_data[0]
    valid_pattern = pattern_data[1]['valid']
    valid_strs = pattern_data[1]['valid_strs']
    invalid_strs = pattern_data[1]['invalid_strs']

    # randomly select a pattern object
    pattern_set = RegexTestSet(name, valid_strs, invalid_strs)

    # give initial prompt
    print(initial_prompt)
    print("Give a regular expression to match {}s".format(name.lower()))
    print("Examples of valid {}s:".format(name.lower()))
    for valid_str in pattern_set.valid_strings:
        print(valid_str)
    
    print("Examples of invalid {}s:".format(name.lower()))
    for invalid_str in pattern_set.invalid_strings:
        print(invalid_str)

    # continue looping until an answer is satisfactory or the user runs out of retries
    while retries >= 1 and not pattern_set.test_pattern(guess):
        guess = input("Enter your guess. You have {} tries left:\n".format(retries))
        try:
            old_guess = guess
            guess = str(guess)
        except ValueError:
            guess = old_guess

        if pattern_set.test_pattern(guess):
            print("Congratulations! Your guess of {} was correct!".format(guess))
        elif guess:
            print("{} is not correct.".format(guess))
            retries -= 1

    if retries == 0 and not pattern_set.test_pattern(guess):
        print("A correct answer was {}".format(valid_pattern))

    exit(1)
