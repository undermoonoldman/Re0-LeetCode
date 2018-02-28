/**344. Reverse String
 * Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".*/

int getStrLen(char* s)
{
    int len = 0;
    char* p = s;
    while(*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

char* reverseString(char* s)
{
    int length = getStrLen(s);
    char* l = s;
    char* r = s + length - 1;
    while(l < r)
    {
        char temp = *l;
        *l = *r;
        *r = temp;
        l++;
        r--;
    }
    return s;
}


#include <stdio.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}