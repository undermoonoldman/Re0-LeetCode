/**131. Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]*/


#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void show(vector<string>& temp)
{
    for(string i : temp)
        cout<<i<<" ";
    cout<<endl;
}

class Solution//搜索空间，有序有限
{
private:
    bool isPalindrome(string s)//判断字符串是否回文
    {
        if(s == string(s.rbegin(), s.rend()))//反转判断相等
            return true;
        else
            return false;
    }

    void helper(string s, vector<vector<string>>& ret, vector<string>& temp)
    {
        if(s.length() == 0)//无法进行切分了，保存并返回
        {
            ret.push_back(temp);
            return;
        }

        for(int i = 0 ; i < s.size() ; i++)
        {
            string pre = s.substr(0, s.size()-i);//对字符串进行前后切分
            string suf = s.substr(s.size()-i, i);

            if(!isPalindrome(pre)) continue;//前部不回文，切分无效，改变切点，继续切分
            temp.push_back(pre);//把回文的前部临时记录
            helper(suf, ret, temp);//继续对后部进行切分
            temp.pop_back();//返回时删除上次尝试的切分
        }
    }


public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        vector<string> temp;
        helper(s, ret, temp);
        return ret;
    }
};

void showVector(vector<vector<string>>& ret)
{
    cout<<"result: \n";
    for(int i = 0 ; i < ret.size() ; i++)
    {

        cout<<"{";
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";
        cout<<"}";

        cout<<endl;
    }
}



int main()
{
    string s = "bb";
    vector<vector<string>> ret = Solution().partition(s);
    showVector(ret);
    return 0;
}