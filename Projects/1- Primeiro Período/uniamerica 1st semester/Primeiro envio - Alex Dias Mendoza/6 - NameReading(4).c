#include <stdio.h>
int main() {
    
    char name[50];

    printf("Type in your name: ");
    scanf("%49s", &name);
    printf("Hello, %s!\n", name);
    
    return 0;
}