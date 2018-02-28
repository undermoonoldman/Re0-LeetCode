#include <malloc.h>
#include <assert.h>

/**412. Fizz Buzz
 * Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]*/

char numToChar(int n)//输入一个 0~9 的整数，输出该整数所对应的字符.例如输入 4 输出 '4'
{
    assert(n >= 0 && n <= 9);
    char ret = '0';
    ret = ret + n;
    return ret;
}

int numLen(int n)//计算整数的位数，有几位
{
    int len = 1;
    int div = 10;
    while(n / div != 0)
    {
        len++;
        div *= 10;
    }
    return len;
}

char* generateFizzBuzz(int n)
{
    if(n == 1)
        return "Fizz";
    else if(n == 2)
        return "Buzz";
    else
        return "FizzBuzz";
}

int getDiv(int n)//计算整数的位数，最高位的单位是多少
{
    int div = 1;
    while(n / div != 0)
    {
        div *= 10;
    }
    return div/10;
}

char* numberToStr(int n)//把数字变为对应的字符串
{
    int len = numLen(n);
    int div = getDiv(n);
    char* ret = malloc(len+1);
    char* p = ret;
    for(int i = 0 ; i < len ; i++)
    {
        int digit = n / div;
        *p = numToChar(digit);
        p++;
        n = n % div;
        div /= 10;
    }
    *p = '\0';
    return ret;
}

char** fizzBuzz(int n, int* returnSize)
{
    *returnSize = n;
    char** ret = (char**)malloc(sizeof(char*) * (n+1));
    for(int i = 1 ; i <= n ; i++)
    {
        if(i % 3 == 0 && i % 5 != 0)
            ret[i-1] = generateFizzBuzz(1);
        else if(i % 3 != 0 && i % 5 == 0)
            ret[i-1] = generateFizzBuzz(2);
        else if(i % 3 == 0 && i % 5 == 0)
            ret[i-1] = generateFizzBuzz(3);
        else
            ret[i-1] = numberToStr(i);
    }
    ret[n] = '\0';
    return ret;
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int* returnSize = (int*)malloc(sizeof(int));
    char** ret = fizzBuzz(15, returnSize);
    for(int i = 0 ; i < *returnSize ; i++)
        printf("%s\n",ret[i]);

    return 0;
}