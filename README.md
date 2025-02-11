# CSE3150Lab02SAMEMILE

# Balanced Lists


## Description
This project generates sequences of `1` and `-1` to test whether they maintain balance after shuffling. The program:
- Creates a sequence with an equal number of `1`s and `-1`s.
- Shuffles the sequence randomly.
- Validates if the shuffled sequence maintains balance.
- Computes the ratio of well-balanced sequences over multiple trials.
- Includes unit tests using the Doctest framework.

## Features
- **Sequence Generation:** Creates a sequence of `1`s and `-1`s of a given length.
- **Shuffling:** Randomly shuffles the generated sequence.
- **Balance Validation:** Checks whether the sequence maintains balance.
- **Testing:** Uses Doctest to verify sequence properties and balance validation.

## Installation & Compilation
### Prerequisites
- C++ Compiler (GCC, Clang, or MSVC)
- [Doctest](https://github.com/doctest/doctest) header file (`doctest.h`)

### Compilation
Use a C++ compiler to compile the program:
```sh
 g++ -std=c++11 -o lab2 lab2.cpp
```

## Usage
Run the compiled executable:
```sh
 ./lab2
```
Enter the sequence size and the number of trials when prompted.

## Example Output
```
@iiso4fun ➜ /workspaces/CSE3150Lab02SAMEMILE (main) $ g++ -std=c++11 -o lab2 lab2.cpp
@iiso4fun ➜ /workspaces/CSE3150Lab02SAMEMILE (main) $ ./lab2
[doctest] doctest version is "2.4.11"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 3 | 3 passed | 0 failed | 0 skipped
[doctest] assertions: 9 | 9 passed | 0 failed |
[doctest] Status: SUCCESS!
Enter sequence size: 
```

## Running Tests
To execute the unit tests:
```sh
 ./lab2
```
Tests will automatically run before prompting for user input.

## Code Structure
- `createSequence(int length)`: Generates a balanced sequence.
- `shuffleSequence(vector<int>& data)`: Shuffles the sequence.
- `validateBalance(const vector<int>& data)`: Checks balance.
- `computeBalancedRatio(int size, int trials)`: Runs multiple trials to compute balance ratio.
- `main()`: Handles user input and test execution.

