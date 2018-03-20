/**18. 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)//固定第一个数，然后进行 3sum 过程.先排序，由于是类似组合问题，不向前搜索，搜索空间逐渐缩小
    {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i <= nums.size() - 3 ; i++)//固定第一个数，只要固定到数组倒数第四个就可以了 nums.size - 3
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;//去重复解
            for(int j = i+1 ; j < nums.size() - 2 ; j++)//3sum 过程
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1, r = nums.size() - 1, sum = target - nums[i] - nums[j];
                while(l < r)
                {
                    if(nums[l] + nums[r] == sum)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(temp);
                        while(l < r && nums[l+1] == nums[l]) l++;
                        while(l < r && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    }
                    else if(nums[l] + nums[r] < sum)
                        l++;
                    else
                        r--;
                }
            }
        }
        return res;
    }
};

void show(vector<vector<int>> ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = Solution().fourSum(nums, 0);
    show(ret);
    return 0;
}