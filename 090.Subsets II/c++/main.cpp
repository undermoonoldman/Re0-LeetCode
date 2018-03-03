/**90. Subsets II
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void helper(vector<vector<int>>& ret, vector<int>& temp, int index, vector<int>& nums)
    {
        ret.push_back(temp);//保存上次构建的子集，保证独一无二
        for(int i = index ; i < nums.size() ; i++)//在已有子集的基础上，尝试集合中为使用过的元素
        {
            if(i != index && nums[i] == nums[i-1]) continue;//当第一次尝试某元素时，不记为重复。当本次尝试与上次尝试元素相同时，记为重复并跳过
            temp.push_back(nums[i]);//往子集临时变量中增加元素
            helper(ret, temp, i+1, nums);//尝试未使用过元素
            temp.pop_back();//完成一次子集构建返回时删除子集最后添加的元素，准备尝试其他元素
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ret;//保存所有子集的集合
        vector<int> temp;//用于计算子集的临时变量
        if(nums.size() == 0)//给定集合为空，子集只有空集
            return ret;
        sort(nums.begin(), nums.end());
        helper(ret, temp, 0, nums);
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
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    vector<vector<int>> ret = Solution().subsetsWithDup(nums);

    showVector(ret);
    return 0;
}