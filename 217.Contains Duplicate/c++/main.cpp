/**217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> been;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(been.find(nums[i]) != been.end())
                return true;
            been.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 3, 0};
    bool check = Solution().containsDuplicate(nums);
    cout<<"check:"<<check<<endl;
    return 0;
}