/**40. Combination Sum II
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]*/

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

class BadSolution//没有减少重复子树的搜索，效率低，如[1,1,2,5,6,7,10]中，以 1 为根节点的子树只有一颗，即 1,2 的搜索只会产生两次。要对结果进行去重，浪费时间
{

private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, vector<int>& candidates, int index)
    {
        if(target < 0)
            return;

        if(target == 0)
        {
            vector<int> Temp = temp;
            sort(Temp.begin(), Temp.end());
            if(find(ret.begin(),ret.end(),Temp) == ret.end())
                ret.push_back(Temp);
            return;
        }

        for(int i = index ; i < candidates.size() ; i++)
        {
            temp.push_back(candidates[i]);
            helper(ret, temp, target-candidates[i], candidates, i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(ret, temp, target, candidates, 0);
        return ret;
    }
};

class Solution//减去了相同子树的搜索，如[1,1,2,5,6,7,10]中，以 1 为根节点的子树只有一颗，即 1,2 的搜索只会产生一次
{

private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, vector<int>& candidates, int index)
    {
        if(target < 0)
            return;

        if(target == 0)
        {
            ret.push_back(temp);
            return;
        }

        for(int i = index ; i < candidates.size() ; i++)
        {
            if(i != index && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            helper(ret, temp, target-candidates[i], candidates, i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(ret, temp, target, candidates, 0);
        return ret;
    }
};

int main()
{
    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(nums, nums+7);
    vector<vector<int>> ret = Solution().combinationSum2(candidates, 8);
    cout<<"result is : \n";
    showVector(ret);
    return 0;
}
