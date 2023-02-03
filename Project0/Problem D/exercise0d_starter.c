#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 10;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){
    for (int a = 1; a < n+1; a++){
        for (int b = 1 ; b < n+1; b++){
            printf("%d ", a*b);
        }
        printf("\n");
    }
}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n) {
    for (double a = 1; a < n + 1; a++) {
        for (double b = 1; b < n + 1; b++) {
            printf("%.2f ", (1 / a) * (1 / b));
        }
        printf("\n");

    }
}