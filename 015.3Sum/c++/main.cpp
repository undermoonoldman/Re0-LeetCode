/**15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],
-4 -1 -1 0 1 2
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)//与 twosum 不同的是，不用找下标了，所以可以直接排序，然后每次固定一个值，用双指针的方法找到另外两个值
    {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());//排序
        for(int i = 0 ; i < nums.size()-2 ; i++)//由于是有序的，所以固定一个值之后 l ,r 指针都在固定值的后面进行查找(类似于组合问题)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;//跳过重复解
            int l = i+1 , r = nums.size() - 1 , sum = 0 - nums[i];
            while(l < r)
            {
                if(nums[l] + nums[r] == sum)
                {
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    res.push_back(vector<int>(temp));
                    while(l < r && nums[l+1] == nums[l]) l++;//跳过重复部分
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
        return res;
    }
};

void show(vector<vector<int>> ret)
{
	for(vector<int> i : ret)
	{
		for(int j : i)
			cout<<j<<" ";
		cout<<endl;
	}
}

int main()
{
	vector<int> nums = {0,0,0};
	vector<vector<int>> ret = Solution().threeSum(nums);
	show(ret);
	return 0;
}