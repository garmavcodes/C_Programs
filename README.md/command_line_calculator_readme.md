# Command-Line Calculator Program in C

This program performs basic math operations (addition, subtraction, multiplication, division) using command-line arguments.

## How it works

1. You run the program from command line with 3 arguments:  
   - Operation name (addition, subtraction, multiplication, division)  
   - First number  
   - Second number  

2. Example command line usage:

./program addition 5 3

3. It checks:
- If arguments are correct.  
- Performs the selected operation.  
- Prints the result.

4. Special case:  
- Division by zero shows a message: "the denominator cannot be zero".

5. If wrong operation is given, it prints "invalid operation".

## How to use

1. Compile the program:

gcc program.c -o program

2. Run with arguments:

./program addition 5 3

3. See the result printed. 

