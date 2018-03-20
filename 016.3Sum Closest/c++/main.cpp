/**16. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)//固定一个数，利用 2sum 遍历所有三元组的组合，记录遍历过的三元组的和最小值
    {
        sort(nums.begin(), nums.end());//先排序，由于是遍历组合，所以只向后搜索，且跳过相同组合,搜索空间逐渐缩小
        int closest = MAX_INPUT;
        for(int i = 0 ; i < nums.size()-2 ; i++)//固定第一个数
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;//跳过相同组合
            int l = i+1, r = nums.size()-1 , sum = target - nums[i];
            while(l < r)//类似 twoSum 的过程
            {

                int temp = (nums[i] + nums[l] + nums[r]);
                if(nums[l] + nums[r] == sum) return target;
                else if(nums[l] + nums[r] < sum)
                {
                    closest = abs(temp-target) < abs(closest-target) ? temp : closest;//只保留最小的和
                    l++;
                }
                else
                {
                    closest = abs(temp-target) < abs(closest-target) ? temp : closest;
                    r--;
                }
            }
        }
        return closest;
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
    vector<int> nums = {-1, 2, 1, -4};
    int ret = Solution().threeSumClosest(nums, 1);
    cout<<ret;
    return 0;
}