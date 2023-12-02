#include <stdio.h>
#include <string.h>

int make_choice();
int input_num_validation(int numSystem, char inputNumber[], int *num);
void display_operations_menu();
void bitwise_operation(int choice, int num1, int num2, int numSystem);

int char_to_digit(char c) {
    return c - '0';     //converting for binar
}

int hex_char_to_digit(char c) {     //converting for hexadecimal
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else {
        return -1;  
    }
}

int main() {
    int numSystemInput = 2, numSystemOutput = 2, num1, num2;
    char inputNumber1[40], inputNumber2[40];

    while (1) {
      
         do {
            if (numSystemInput != 2 && numSystemInput != 10 && numSystemInput != 16) {
                printf("Invalid choice. Please try again.\n");     
            }
            printf("Enter number system for input (2 for binary, 10 for decimal, 16 for hexadecimal) ");
            numSystemInput = make_choice();
        } 
        while (numSystemInput != 2 && numSystemInput != 10 && numSystemInput != 16); 
        
        do {
            if (numSystemOutput != 2 && numSystemOutput != 10 && numSystemOutput != 16) {
                printf("Invalid choice. Please try again.\n");     
            }
            printf("Enter number system for output (2 for binary, 10 for decimal, 16 for hexadecimal) ");
            numSystemOutput = make_choice();
        } 
        while (numSystemOutput != 2 && numSystemOutput != 10 && numSystemOutput != 16); 
        
        int t = 0;
        while (1) {
            display_operations_menu();
            int choice = make_choice();
                if (choice == 7) {
                    break; 

                }
                if (choice == 8) {
                    t = 1;
                    break; 
                }

                else if (choice < 1 || choice > 7){
                    printf("Invalid choice. Please try again.\n");
                    continue;
                }
            
                do {
                    printf("Enter the first number: ");
                }
                while (!input_num_validation(numSystemInput, inputNumber1, &num1));

                do {
                    printf("Enter the second number: ");
                }
                while (!input_num_validation(numSystemInput, inputNumber2, &num2));
                    
                bitwise_operation(choice, num1, num2, numSystemOutput);
            
            
            if (t) {
            break; 
        }
        }
        if (t) {
            break; 
        }
    }
    return 0;
}

int make_choice() {     // makeing validations for inserting chars
    int choice = 0;
    while (1) {
        int read_status = scanf("%d", &choice);
        if (read_status == 1) {
            break;
        } else {
            while (getchar() != '\n');  // Clear the input buffer
            break;
        }
    }
    return choice;
}

int input_num_validation(int numSystem, char inputNumber[], int *num) {     // Validation for the number system
    scanf("%s", inputNumber);

    *num = 0;

    if (numSystem == 2) {        // Binary input
        if (strlen(inputNumber) < 2 || inputNumber[0] != '0' || inputNumber[1] != 'b') {
            printf("Invalid binary input. Binary numbers should start with 0b. Try again.\n");
            return 0;  // Validation failed
        }

        for (int i = 2; i < strlen(inputNumber); i++) {
            if (inputNumber[i] != '0' && inputNumber[i] != '1') {
                printf("Invalid binary input. Try again.\n");
                return 0;  // Validation failed
            }
            *num = (*num << 1) + char_to_digit(inputNumber[i]);
        }
    } 
    
    else if (numSystem == 10) {   // Decimal input
            for (int i = 0; i < strlen(inputNumber); i++) {
                if (inputNumber[i] < '0' || inputNumber[i] > '9') {
                    printf("Invalid decimal input. Try again.\n");
                    return 0;  // Validation failed
                }
                *num = (*num * 10) + char_to_digit(inputNumber[i]);
            }
    } 

    else if (numSystem == 16) {   // Hexadecimal input
        if (strlen(inputNumber) < 2 || inputNumber[0] != '0' || inputNumber[1] != 'x') {
            printf("Invalid hexadecimal input. Hexadecimal numbers should start with '0x'. Try again.\n");
            return 0;  // Validation failed
        }

        for (int i = 2; i < strlen(inputNumber); i++) {
            int digit = hex_char_to_digit(inputNumber[i]);
            if (digit == -1) {
                printf("Invalid hexadecimal input. Try again.\n");
                return 0;  // Validation failed
            }
            *num = (*num << 4) + digit;
        }
    }

    return 1;  // Validation passed
}


void display_operations_menu() {
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOR\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Reply\n");
    printf("8. Exit\n");
    printf("Choose operation ");
}

void bitwise_operation(int choice, int num1, int num2, int numSystem) {
    int result;

    switch (choice) {
        case 1: // AND
            result = num1 & num2;
            break;
        case 2: // OR
            result = num1 | num2;
            break;
        case 3: // XOR
            result = num1 ^ num2;
            break;
        case 4: // NOR
            result = ~(num1 | num2);
            break;
        case 5: // Left Shift
            result = num1 << num2;
            break;
        case 6: // Right Shift
            result = num1 >> num2;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    if (numSystem == 2) {
        printf("Result (Binary): ");
        for (int i = 31; i >= 0; i--) {
            printf("%d", (result >> i) & 1);
        }
        printf("\n");
    }

    else if (numSystem == 10) {
        printf("Result (Decimal): %d\n", result);
    }

    else if (numSystem == 16) {
        printf("Result (Hexadecimal): %X\n", result);
    }
}
