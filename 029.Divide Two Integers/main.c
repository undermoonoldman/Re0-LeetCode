/*29. Divide Two Integers
 * Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    int sign = (float) dividend / divisor > 0 ? 1 : -1;
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;
    unsigned int bit_num[33];
    unsigned int i = 0;
    long long d = dvs;

    bit_num[i] = d;
    while (d <= dvd) {
        bit_num[++i] = d = d << 1;
    }
    i--;

    unsigned int result = 0;
    while (dvd >= dvs) {
        if (dvd >= bit_num[i]) {
            dvd -= bit_num[i];
            result += (1<<i);
        } else {
            i--;
        }
    }

    //becasue need to return `int`, so we need to check it is overflowed or not.
    if (result > INT_MAX && sign > 0) {
        return INT_MAX;
    }
    return (int) result * sign;
}

int main()
{
    int a = 10;
    int b = 3;
    int c = divide(a, b);

    printf("c = %d\n",c);
    return 0;
}