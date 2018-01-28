/*30. Substring with Concatenation of All Words
 *
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
 */
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

int KMP(char *str, char *pat, int start)
{
    int *longestPrefix = computePrefix(pat);
    int m = strlen(str);
    int n = strlen(pat);

    for(int i = start, j = 0 ; i < m ; i++)
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

int strStr(char* haystack, char* needle, int i)
{
    if(*haystack == 0 && *needle == 0)
        return 0;
    if(*haystack != 0 && *needle == 0)
        return 0;
    return KMP(haystack, needle, i);
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int resultSize = strlen(s) / (strlen(words[0]) * wordsSize);
    int resultArray[resultSize];
}

int main() {
    printf("Hello, World!\n");
    return 0;
}