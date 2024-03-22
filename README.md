# Num Converter

Num converter is a program designed to demonstrate the debugging process using tools such as GDB and Valgrind.

## Files Used by the Program

- Makefile
- main.cpp: Handles user input and calls appropriate functions.
- BaseNumber.h/cpp: Contains the main conversion logic.
- BaseCalc.h/cpp: Includes some arithmetic operations performed on BaseNumber.
- util.hpp: Includes utilities used by the program and manages input validation for automatic mode.

## Installation

1. Clone this repository using `git clone`.
2. Run `make` to execute the Makefile. (Note: There might be issues.)

## Valid Execution

Run the program with the following command-line arguments: `./calculator ifile ofile <0 | 1>`

## Program Modes

### 0) Automatic Mode

In automatic mode, the program reads input from an input file (`ifile`) if prompted by the user. Valid commands include:

- `Help`: Displays valid commands (This Page)
- `Init`: Reads the numbers from `ifile` and stores them in a vector.
- `Convert`: Converts the array
  - `HEX`: Converts read values to hexadecimal.
  - `BIN`: Converts read values to binary.
  - `DEC`: Converts read values to decimal.
- `Save`: Saves the array to `ofile`.
- `Print`: Prints the active working array.
- `Total`: Prints the total of the active working array.
- `Stop`: Exits the program.

### 1) Manual Mode

In manual mode, the user is prompted to enter a number, using the prefixes "0d" for decimal, "0b" for binary, and "0x" for hexadecimal. After entering the number, the user can perform the following operations using the index:

0. Exit: Exits the program.
1. Convert to binary: Converts the previously entered number to binary.
2. Convert to hexadecimal: Converts the previously entered number to hexadecimal.
3. Convert to decimal: Converts the previously entered number to decimal.
4. Arithmetic Operations: Prompts the user to enter another number and perform addition or subtraction.
