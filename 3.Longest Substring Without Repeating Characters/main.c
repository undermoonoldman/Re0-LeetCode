/*3. Longest Substring Without Repeating Characters
 Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

最长不重复子串


  */



#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int lengthOfLongestSubstring1(char* s)//双循环法，分别计算每个位置的最长子串，O(nlogn)
{
    char *t = s;
    int max = 0;
    while(*t)
    {
        char *u = t;
        int count = 0;
        int freq[128];
        memset(freq,0,128* sizeof(int));
        while(*u)
        {
            if(freq[(int)*u] == 1)
            {
                break;
            }
            count++;
            freq[(int)*u] = 1;
            u++;
        }
        if(count > max)
            max = count;
        t++;
    }
    return max;
}

/*滑动窗口，O(n)，左窗口l，右窗口r，左窗口跟右窗口初始都为串的头，最长子串长度初始化为零。当右窗口移到串的尾部时，匹配终止，当右窗口不重复时，右窗口不断右移，不断更新最长子串长度（比较当前最长子串长度与左右窗口距离）与字符出现的频度数，当再一次右
  窗口出现重复时，说明当前右窗口与左窗口直接存在着重复（不清楚是具体哪一位重复），于是这时只好不断右移左窗口，并把左窗口字符的频度数减一（相当于忘记），当左窗口跨过重复字符时，就不再冲突了，*/

int lengthOfLongestSubstring2(char* s)
{
    char *l = s;//
    char *r = s;
    int maxSub = 0;
    int count = 0;
    int freq[128];
    memset(freq,0,128* sizeof(int));
    while(*r)
    {
        if(freq[(int)*r] == 1)
        {
            (freq[(int)*l]) -= 1;
            //r--;
            l++;
        }
        else
        {
            (freq[(int)*r]) += 1;
            r++;
        }
        maxSub = max(maxSub,r-l);
    }
    return maxSub;
}

int main()
{
    printf("Hello, World!\n");

    //printf("a = %d A = %d z = %d Z = %d\n",'a','A','z','Z');

    char a[] = "abcaadef";


    int max1 = lengthOfLongestSubstring1(a);
    int max2 = lengthOfLongestSubstring2(a);

    printf("max1 = %d    max2 = %d\n",max1,max2);

    return 0;
}