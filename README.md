# ModelProgram

Model Program to be used to demonstrate the debugging process using tools such as GDB and Valgrind.

## Execution

- Valid Execution: `./modelProgram ifile ofile <mode>`
- Mode:
  - **0**: Operations are performed on ifile values
  - **1**: User is prompted for a buffer input
- Program should have the following commands:
  - **Init**: Reads the numbers from `ifile` and stores them in a vector.
  - **Convert <secondCommand>**: Converts the array
    - `D2B`: Converts decimal to binary.
    - `B2H`: Converts binary to hex.
    - `D2H`: Converts decimal to hex (built using D2B & B2H).
    - `H2B`: Converts hex to binary.
    - `B2D`: Converts binary to decimal.
    - `H2D`: Converts hex to decimal.
  - **Save**: Saves the array to `ofile`.
  - **Print <index>**: If no index is provided, it prints the whole array.
  - **Stop**: Exits the program
  - ** <SOME ARITH FUNCTIONS?>

## Structure

- Superclass: number
- Subclasses:
  - hex
  - binary
  - decimal

