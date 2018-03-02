/**8. String to Integer (atoi)
 * Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.



Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 实现 atoi，将字符串转为整数。

提示：仔细考虑所有输入情况。如果你想挑战自己，请不要看下面并自己考虑所有可能的输入情况。

说明：这题解释的比较模糊（即没有指定输入格式）。你得事先汇集所有的输入情况。



atoi的要求：

这个函数需要丢弃之前的空白字符，直到找到第一个非空白字符。之后从这个字符开始，选取一个可选的正号或负号后面跟随尽可能多的数字，并将其解释为数字的值。

字符串可以在形成整数的字符后包括多余的字符，将这些字符忽略，这些字符对于函数的行为没有影响。

如果字符串中的第一个非空白的字符不是有效的整数，或者没有这样的序列存在，字符串为空或者只包含空白字符则不进行转换。

如果不能执行有效的转换，则返回 0。如果正确的值超过的可表示的范围，则返回 INT_MAX（2147483647）或 INT_MIN（-2147483648）。*/


#define INT_MAX 2147483647
#define INT_MIN-2147483648

int myAtoi(char* str) {
    //注意：判断空字符串数组
    if(*str == '\0') return 0;
    long long llnum = 0;
    int sign = 1;

    while (*str == ' ')
    {
        str++;
    }
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
        //注意：不要溜了要判断+号的情况
    else if(*str == '+')
    {
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        int i = *str - '0';
        llnum = llnum*10 + i;
        if (llnum*sign > INT_MAX)
        {
            llnum = INT_MAX;
            break;
        }
        else if (llnum*sign < INT_MIN)
        {
            llnum = INT_MIN;
            break;
        }
        str++;
    }
    return (int)(sign*llnum);
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int converted = myAtoi(" 1234 ");
    printf("converted is : %d\n",converted);
    return 0;
}