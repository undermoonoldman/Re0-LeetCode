#include <vector>

/**49. Group Anagrams
 * Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

*/
#include <iostream>
#include <map>

using namespace std;


class Solution
{
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;//返回值
        map<string, vector<string>> count;//根据字符串所属的 anagram 来映射 vector

        for(string i : strs)//遍历所有的字符串
        {
            string temp = i;
            sort(temp.begin(), temp.end());//对每次遍历的串排序，属于同一个 anagram 的排序结果相同

            map<string, vector<string>>::iterator ite;
            ite = count.find(temp);//根据排序产生的 anagram 找到对应的 vector<string>

            if(ite != count.end())//找到了，添加当前串
                ite->second.push_back(i);

            else//没找到，新创建一个并完成添加
            {
                vector<string> lala;
                lala.push_back(i);
                count.insert(pair<string, vector<string>>(temp, lala));
            }
        }


        map<string, vector<string>>::iterator ite;
        for(ite = count.begin() ; ite != count.end() ; ite++)
            ret.push_back(ite->second);

        return ret;
    }
};




int main()
{
    //"eat", "tea", "tan", "ate", "nat", "bat"
    vector<string> test;
    test.push_back("eat");
    test.push_back("tea");
    test.push_back("tan");
    test.push_back("ate");
    test.push_back("nat");
    test.push_back("bat");
    vector<vector<string>> ret = Solution().groupAnagrams(test);

    for(int i = 0 ; i < ret.size() ; i++)
    {
        cout<<endl;
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";
    }

    return 0;
}