#include <stdio.h>
#include <stdlib.h>
//todo
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    return 1.1;
}
int getStringLength(char *s)
{
    char *ps = s;
    int length = 0;
    while(*ps)
    {
        length++;
        ps++;
    }
    return length;
}

char* longestPalindrome(char* s)
{
    int length = getStringLength(s);
    int newLength = 2 * length + 1;
    int longestSub[newLength];
    int longest = 0;
    int longestIndex;
    char *newS = (char*)malloc((newLength+1) * sizeof(char));
    for(int i = 1 ; i <= newLength ; i++)
    {
        if(i % 2 == 0)
            newS[i-1] = s[(i-1)/2];
        else
            newS[i-1] = '#';
    }
    newS[newLength] = '\0';

    for(int i = 0 ; i <= newLength-1 ; i++)
    {
        int count = 0;
        int l = i-1;
        int r = i+1;
        while(newS[l] == newS[r] && l >= 0 && r <= newLength-1)
        {
            count++;
            l--;
            r++;
        }
        longestSub[i] = count;
        if(longest < count)
        {
            longest = count;
            longestIndex = i;
        }
    }

    char *ret = (char*)malloc((longest+1) * sizeof(char));

    int l = longestIndex - longest;
    int r = longestIndex + longest;
    int index = 0;
    for(int i = l ; i <= r ; i++)
    {
        if(newS[i] != '#')
            ret[index++] = newS[i];
    }
    ret[longest] = '\0';

    return ret;
}

int main()
{
    printf("Hello, World!\n");
    //printf("a = %d A = %d # = %d\n",'a','A','#');
    char a[] = "a";
    printf("a is %s\n",a);

    char *newA = longestPalindrome(a);
    printf("the length of a is %d\n",getStringLength(a));
    printf("the newA is %s\n",newA);

    return 0;
}