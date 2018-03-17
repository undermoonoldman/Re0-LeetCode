/**242. Valid Anagram
 * Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)//用map o(N) 用排序比价 o(logN)
    {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mapS;//直接在一个map上操作更快
        for(char i : s)
            mapS[i]++;
        for(char i : t)
            mapS[i]--;
        for(char i : s)
            if(mapS[i]) return false;
        return true;
    }
};

int main()
{
    string a = "abc";
    string b = "bca";
    bool check = Solution().isAnagram(a, b);
    cout<<check<<endl;
    return 0;
}