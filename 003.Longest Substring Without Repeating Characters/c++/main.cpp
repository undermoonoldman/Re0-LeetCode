/**3. Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)//滑动窗口
    {
        if(s == "") return 0;//特殊情况处理
        int l = 0;//左窗口
        int r = 0;//右窗口
        int ret = 1;//最长子串初始值
        int freq[256] = {0};//记录窗口中字符出现的次数
        freq[s[0]] = 1;//初始化
        while(l < s.size())
        {
            if(r+1 < s.size() && freq[s[r+1]] == 0)//右窗口还能扩展而且待扩展的位置还没有被使用过
                freq[s[++r]]++;//扩展右窗口，更新频率统计
            else//右窗口到底或者待扩展的位置与窗口中有冲突
                freq[s[l++]]--;//把左窗口收缩到冲突位置的右面
            ret = max(ret, (r-l+1));//ret值计算是贪心的，无论是右窗口到底还是产生了冲突都不会让ret减少
        }
        return ret;
    }
};

int main()
{
    string s = "abcabcbb";
    int res = Solution().lengthOfLongestSubstring(s);
    cout<<"res:"<<res<<endl;
    return 0;
}