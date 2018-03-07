/**283. Move Zeroes
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int p = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != 0)
            {
                nums[p] = nums[i];
                p++;
            }
        }

        for(int i = p ; i < nums.size() ; i++)
            nums[i] = 0;

    }
};

void showVec(vector<int>& nums)
{
    for(int i : nums)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vector<int> nums = {1,0,0};
    showVec(nums);
    Solution().moveZeroes(nums);
    showVec(nums);
    return 0;
}