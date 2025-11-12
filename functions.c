#include <stdio.h>

// Function declarations (prototypes)
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main() {

    int x = 10, y = 5;
    int result1, result2, result3;

    // ✅ FUNCTION CALLS
    result1 = add(x, y);        // calling add()
    result2 = subtract(x, y);   // calling subtract()
    result3 = multiply(x, y);   // calling multiply()

    // printing results
    printf("Addition: %d\n", result1);
    printf("Subtraction: %d\n", result2);
    printf("Multiplication: %d\n", result3);

    return 0;
}

// ✅ FUNCTION DEFINITIONS
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}
