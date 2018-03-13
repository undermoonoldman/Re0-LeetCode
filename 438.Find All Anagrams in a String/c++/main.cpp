/**438. Find All Anagrams in a String
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {//若果采用截取子串排序的方法会造成超时 nlogN
public:
    vector<int> findAnagrams(string s, string p)//字符串同构异形，找出在 s 串中所有与 p 同构异形的子串的下标集合
    {
        vector<int> ret;
        sort(p.begin(), p.end());
        if(s == "" || p == "" || s.length() < p.length()) return ret;//特殊情况
        int freqS[256] = {0};
        int freqP[256] = {0};
        for(int i = 0 ; i < p.length() ; i++)//初始化字符频率统计数组
        {
            freqP[p[i]]++;
            freqS[s[i]]++;
        }
        int l = 0;
        int r = p.length() - 1;//窗口大小固定为 p 的长度
        while(r < s.length())//右窗口到底就停止
        {
            if(!memcmp(freqP, freqS, sizeof(freqP)))//查看当前窗口的统计数组是否与 P 的统计数组相同，相同就找到一个同构
                ret.push_back(l);
            //窗口整体向右移动一格，并维持相应数据
            freqS[s[l]]--;
            l++;
            freqS[s[r+1]]++;
            r++;
        }
        return ret;
    }
};

int main()
{
    string a = "abab";
    string b = "ab";
    vector<int> ret = Solution().findAnagrams(a, b);
    for(int i : ret)
        cout<<i<<" ";

    return 0;
}