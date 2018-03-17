/**205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)//对于终点相同的映射，其起点也相同
    {
        unordered_map<char, char> reflect;//记录映射
        unordered_set<char> been;//记录终点
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(reflect.count(s[i]) == 0)//起点为出现过
            {
                if(been.count(t[i]) != 0) return false;//终点已经存在了，说明重复映射
                reflect[s[i]] = t[i];//插入映射
                been.insert(t[i]);//记录终点
            }

            else
                if(reflect[s[i]] != t[i]) return false;//不是所期待的映射
        }
        return true;
    }
};

int main()
{
    string s = "ab";
    string t = "aa";
    bool check = Solution().isIsomorphic(s, t);
    cout<<"check:"<<check<<endl;
    return 0;
}