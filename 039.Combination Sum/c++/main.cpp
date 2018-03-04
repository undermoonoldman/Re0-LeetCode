/**39. Combination Sum
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
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

class BadSolution//低效版本，有大量无用搜索分支，搜索了降序序列导致重复时间浪费
{

private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, vector<int>& candidates)
    {
        if(target < 0)
        {
            return;
        }

        if(target == 0)
        {
            vector<int> Temp = temp;
            sort(Temp.begin(), Temp.end());
            if(find(ret.begin(),ret.end(),Temp) == ret.end())
                ret.push_back(Temp);
            return;
        }

        for(int i = 0 ; i < candidates.size() ; i++)
        {
            if(i != 0 && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            helper(ret, temp, target-candidates[i], candidates);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(ret, temp, target, candidates);
        return ret;
    }
};

class Solution//减少了无用的重复搜索，只搜索升序序列
{

private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int target, vector<int>& candidates, int index)
    {
        if(target < 0)
        {
            return;
        }


        if(target == 0)
        {
            ret.push_back(temp);
            return;
        }

        for(int i = index ; i < candidates.size() ; i++)
        {
            temp.push_back(candidates[i]);
            helper(ret, temp, target-candidates[i], candidates, i);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(ret, temp, target, candidates, 0);
        return ret;
    }
};



int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    vector<vector<int>> ret = BadSolution().combinationSum(candidates, 4);
    cout<<"result is : \n";
    showVector(ret);
    return 0;
}