/**290. Word Pattern
 * Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        vector<string> res;

        //以" " 为切分，找到每个节点对应的子串，存到 vector中
        int last = 0;
        int index = str.find(' ', 0);
        if(index == -1) res.push_back(str.substr(last, index-last));
        else
        {
            while(last < str.size())
            {
                string temp = str.substr(last, index-last);
                res.push_back(temp);
                last = index + 1;
                index = str.find(' ', last);
                if(index == -1) index = str.size();
            }
        }

        if(pattern.length() != res.size()) return false;//切分出的子串总数与模式字符串的字符总数不相等，直接返回false

        unordered_set<string> been;
        unordered_map<char, string> reflect;

        for(int i = 0 ; i < pattern.size() ; i++)//正常的映射过程
        {
            if(reflect.count(pattern[i]) == 0)
            {
                if(been.count(res[i]) != 0) return false;
                reflect[pattern[i]] = res[i];
                been.insert(res[i]);
            }

            else
            if(reflect[pattern[i]] != res[i]) return false;
        }
        return true;
    }
};

int main()
{
    string pattern = "e";
    string str = "eukera";
    bool check = Solution().wordPattern(pattern, str);
    cout<<"check:"<<check<<endl;
    return 0;
}