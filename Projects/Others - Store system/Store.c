#include <stdio.h>
#include <windows.h>

void intVerification(input) {
    if (input != int) {
        printf("Invalid input. Please enter an integer.\n");
    }
}

int main() {
int input = 0;

do{
    printf("Welcome to the Store System!\n");
    printf("Please enter a number (1-3) to select an option:\n");
    printf("1. Checkout Menu\n");
    printf("2. Add Items\n");
    printf("3. Exit\n");
    scanf("%d", &input);
    intVerification(input);
} while
}