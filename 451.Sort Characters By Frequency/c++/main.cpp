/**451. Sort Characters By Frequency
 * Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<char, int> PAIR;

struct CmpByValue//自定义 pair 比较函数
{
    bool operator()(const PAIR& l, const PAIR& r)
    {
        return l.second > r.second;
    }
};


class Solution
{
private:
    CmpByValue cmpByValue;

public:
    string frequencySort(string s)//map由于底层机制在插入时对 key 进行了排序，但我们要对 value 进行排序，这里只能把 pair 取出来对 pair 进行排序了
    {
        map<char, int> freq;//词频统计
        for(char i : s)
            freq[i]++;

        vector<PAIR> res(freq.begin(), freq.end());//取出
        sort(res.begin(), res.end(), cmpByValue);//排序，传入比较函数
        string ret;

        for(PAIR i : res)//生成字符串
            for(int j = 0 ; j < i.second ; j++)
                ret += i.first;

        return ret;
    }
};

int main()
{
    string s = "Aabb";
    string ret = Solution().frequencySort(s);
    cout<<"ret :"<<ret<<endl;
    return 0;
}