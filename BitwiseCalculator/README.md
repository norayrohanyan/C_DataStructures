# Bitwise Operation Calculator

## Program Description

The provided C program is a simple bitwise operation calculator that allows users to perform various bitwise operations on two numbers. The program supports binary, decimal, and hexadecimal number systems. It includes functions for input validation, bitwise operations, and a user-friendly menu for interaction.

### Parts of the Program

1. **Main Function (`main`):**
   - The main function initializes variables, including the number systems for input and output, and enters a loop to continuously prompt the user for input.
   - Within the loop, the program displays the operations menu and performs the selected bitwise operation based on user input.
   - The program also allows the user to change the input and output number systems.

2. **User Input Functions:**
   - The `make_choice` function takes user input for menu choices and ensures valid integer input.
   - The `input_num_validation` function validates user input for the numbers to be operated on, based on the selected number system.

3. **Bitwise Operation Function (`bitwise_operation`):**
   - This function performs the bitwise operation based on the user's choice (AND, OR, XOR, NOR, Left Shift, Right Shift) and prints the result in the chosen number system.

4. **Display Operations Menu Function (`display_operations_menu`):**
   - This function displays the menu of available bitwise operations for the user to choose from.

5. **Compilation and Execution Instructions:**
   - To compile the program, use a C compiler such as `gcc`:

     ```bash
     gcc bitwise_calculator.c -o bitwise_calculator
     ```

   - To execute the compiled program:

     ```bash
     ./bitwise_calculator
     ```

## User Manual

1. Upon running the program, you will be prompted to enter the number system for input (2 for binary, 10 for decimal, 16 for hexadecimal).

2. Next, you will be asked to choose the number system for output.

3. The program will display a menu of bitwise operations. Enter the corresponding number to choose an operation.

4. If you want to exit the program, choose option 8.

5. For bitwise operations requiring input numbers, you will be prompted to enter the first and second numbers based on the selected number system.

6. The program will display the result of the bitwise operation in the chosen number system.

7. To perform another operation, the program will return to the menu. To exit, choose option 8.

**Note**: Invalid inputs will prompt the program to ask for input again.
