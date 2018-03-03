/**77. Combinations
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:

    void helper(vector<vector<int>>& ret, vector<int>& temp, int n, int k, int index)
    {
        if(k == 0)//每当取完了 k 个数，储存一次并返回
        {
            ret.push_back(temp);
            return;
        }



        for(int i = index ; i <= n ; i++)//给出的取值范围是有序递增的，所以每次考虑的值 i 不会减小，每次都增加. 例如:考虑 [12]不考虑[21]
        {
            temp.push_back(i);
            helper(ret, temp, n, k-1, i+1);//每取到一位，计数器 k - 1
            temp.pop_back();//返回后清楚上次尝试的最后一位，进行下一次尝试
        }
    }

public:

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, temp, n, k, 1);
        return ret;
    }
};

void showVector(vector<vector<int>>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";

        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> ret = Solution().combine(4, 2);
    showVector(ret);
    return 0;
}