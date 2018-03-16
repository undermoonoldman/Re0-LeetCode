/**76. Minimum Window Substring
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)//不用每次都对window串进行计算，只记录最短窗口的左边跟宽度，在最后计算出window串
    {
        vector<int> freq(256, 0);//hash数组
        for(char i : t)
            freq[i]++;//初始化，有效的字符为正数，无效的字符为零(t 中的字符为有效字符)
        int l = 0;
        int r = 0;
        int begin = 0;

        int count = t.length();
        int len = INT32_MAX;

        while(r < s.length())
        {
            if(freq[s[r]]-- > 0) count--;//右窗口扩展，遇到有效字符，减计数器. 无效字符不会减计数器(有效字符会减到零，无效字符减为负数)
            while(count == 0)//当计数器减到零，所有有效字符都处在窗口里了(右窗口为有效字符，左窗口不一定是有效字符)
            {
                if(r-l+1 < len)
                {
                    begin = l;
                    len = r-l+1;
                }

                if(freq[s[l++]]++ == 0) count++;//左窗口扩展，有效字符让计数器增加，无效字符不会让计数器增加(由此去掉左边的无效字符)
            }
            r++;//扩展右窗口
        }
        return (len == INTMAX_MAX) ? "" : s.substr(begin, len);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ret = Solution().minWindow(s, t);
    cout<<ret;

    return 0;
}