#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursive(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1, fib = 0;
    for (int i = 3; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
        return 1;
    }

    int input_integer = atoi(argv[1]);

    char method = argv[2][0];

    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[3]);
        return 1;
    }

    int file_integer;
    fscanf(file, "%d", &file_integer);
    fclose(file);

    int N = input_integer + file_integer;

    int result = 0;
    if (method == 'r') {
        result = fibonacci_recursive(N);
    } else if (method == 'i') {
        result = fibonacci_iterative(N);
    } else {
        printf("Error: Invalid method '%c'. Use 'r' for recursive or 'i' for iterative.\n", method);
        return 1;
    }

    printf("%d\n", result);

    return 0;
}
