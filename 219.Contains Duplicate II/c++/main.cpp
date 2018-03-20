/**219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)//题目转化为 : 在大小最大为 k 的窗口中找是否有重复，出现重复则返回 true
    {
        unordered_set<int> been;
        for(int i = 0 ; i < nums.size() ; i++)//窗口大小从零开始
        {
            if(been.find(nums[i]) != been.end())//出现重复，返回 true
                return true;
            been.insert(nums[i]);//没有出现重复，记录频次,纳入窗口中
            if(been.size() > k)//如果窗口在右边界扩展后大小超过 k,就把窗口左边界收缩一个单位
                been.erase(nums[i-k]);
        }
        return false;//遍历完了数组都没有找到，返回 false
    }
};

int main()
{
    return 0;
}