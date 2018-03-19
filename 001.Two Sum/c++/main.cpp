/**1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) //把元素放入表中，在遍历 nums 的过程中，每取一个数temp，看 target-temp 在表中是否存在，存在就说明找到解
    {
        unordered_map<int, int> pos;//如果把所有的元素都遍历放入表中的话，会出现相同元素的覆盖，这时 target 如果是由相同元素组成的解的话就无法找到了
        vector<int> ret;
        for(int i = 0 ; i < nums.size() ; i++)//在遍历 num 时不着急把当前值放入表，先看表中是否存在解(排除相同元素的解的情况)，存在解的话返回解题，不存在的话把当前元素放入表
        {
        	if(pos.find(target - nums[i]) != pos.end())
        	{
        		ret.push_back(i);
        		ret.push_back(pos[target - nums[i]]);
        		return ret;
        	}
        	else
        		pos[nums[i]] = i;
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};

int main()
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> ret = Solution().twoSum(nums, target);
	for(int i : ret)
		cout<<i<<" ";
	return 0;
}