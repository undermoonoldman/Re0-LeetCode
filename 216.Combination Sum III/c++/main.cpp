/**216. Combination Sum III
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]*/

#include <iostream>
#include <vector>

using namespace std;

void show(vector<int>& temp)
{
    for(int i = 0 ; i < temp.size() ; i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}

void showVector(vector<vector<int>>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";

        cout<<endl;
    }
}

class Solution//本题候选集合为 1~9 有序无重复. 有步骤限制
{

private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, int index, int step)
    {

        if(step == 0)//步骤到期就可以返回剪枝了,不用等到 target <= 0 的情况
        {
            if(target == 0)
                ret.push_back(temp);

            return;
        }

        for(int i = index ; i <= 9 ; i++)
        {
            temp.push_back(i);
            helper(ret, temp, target- i , i+1, step-1);//候选集合没有重复，而且只搜索升序序列，故 i+1
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, temp, n, 1, k);
        return ret;
    }
};



int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    vector<vector<int>> ret = Solution().combinationSum3(3, 9);
    cout<<"result is : \n";
    showVector(ret);
    return 0;
}