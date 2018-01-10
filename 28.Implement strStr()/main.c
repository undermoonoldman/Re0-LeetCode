/*28. Implement strStr()
 *
 * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1


 利用 KMP 算法解决*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showArray(int *array, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d -> ",array[i]);
    }
    printf("\n");
}

int* computePrefix(char *pat)
{
    int len = strlen(pat);

    int *longestPrefix = (int*)malloc(sizeof(int) * len);
    longestPrefix[0] = 0;
    for(int i = 1, j = 0 ; i < len ; i++)
    {
        while(j > 0 && pat[j] != pat[i])
            j = longestPrefix[j-1];

        if(pat[j] == pat[i])
            longestPrefix[i] = ++j;
        else
            longestPrefix[i] = j;
    }
    return longestPrefix;
}

int KMP(char *str, char *pat)
{
    int *longestPrefix = computePrefix(pat);
    int m = strlen(str);
    int n = strlen(pat);

    for(int i = 0, j = 0 ; i < m ; i++)
    {
        while(j > 0 && str[i] != pat[j])
            j = longestPrefix[j-1];

        if(str[i] == pat[j])
            j++;

        if(j == n)
            return i-n+1;
    }
    return -1;
}

int strStr(char* haystack, char* needle)
{
    if(*haystack == 0 && *needle == 0)
        return 0;
    if(*haystack != 0 && *needle == 0)
        return 0;
    return KMP(haystack, needle);
}

int main()
{
    printf("Hello, World!\n");
//    char *a = "mississippi";
//    char *b = "issip";
    char *a = "ababcaababcaabc";
    char *b = "ababcaabc";
    int index = strStr(a,b);
    printf("index: %d\n",index);
    return 0;
}
