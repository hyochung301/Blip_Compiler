#include <stdio.h>
/*
 * Write a function which calculates the Greatest Common Divisor (https://en.wikipedia.org/wiki/Greatest_common_divisor)
of two given integers. It should have the following signature:

int gcd(int x, int y)

You may assume that both x and y are positive integers and x is greater than or equal to y.
Using the function mentioned above, print out the gcd of following integer pairs:
{ (48, 18), (144, 60), (65, 12), (179, 7) }

Your program should take no input and the output should be similar to this:
"""
GCD of 48 and 18 is: 6
GCD of 144 and 60 is: 12
GCD of 65 and 12 is: 1
GCD of 179 and 7 is: 1
"""

*/


void GCD(int n1, int n2) {
    int i, gcd;
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    printf("GCD of %d and %d is: %d\n",n1,n2,gcd);
}

int main() {
    GCD(48, 18);
    GCD(144, 60);
    GCD(65, 12);
    GCD(179, 7);

    return 0;
}
