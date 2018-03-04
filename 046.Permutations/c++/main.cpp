/**046.Permutations
 * Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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

class Solution//搜索空间有序，无重复。搜索可以降序，不能对子树搜索同一个分支. 例如: 1 1 1 搜索了同一个分支， 1 2 3, 3 2 1 升降序无所谓
{
private:
    vector<bool> used;//避免搜索同一分支建立一个标记数组，

    void helper(vector<vector<int>>&ret, vector<int>& p, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ret.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!used[i])
            {
                used[i] = true;//进入子树分支前标记以占用的分支
                p.push_back(nums[i]);

                helper(ret, p, nums, index+1);
                //子分支返回后清楚标记，否则无法进入兄弟分支. 例如:1 2 3，若不清楚标记，无法进行 2,?,? 的搜索
                used[i] = false;//这里赋值的单等号写成双等号了，gg找了一下午
                p.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        used = vector<bool>(nums.size(), false);

        helper(ret, temp, nums, 0);
        return ret;
    }
};


int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(3);
    vector<vector<int>> ret = Solution().permute(candidates);
    cout<<"result is : \n";
    showVector(ret);
    return 0;
}