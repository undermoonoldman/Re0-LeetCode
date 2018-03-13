/**209. Minimum Size Subarray Sum
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if(nums.size() == 0) return 0;//特殊情况
        int ret = nums.size() + 1;//窗口初始化为一个不可能取到的最大值
        int begin = ret;
        int l = 0;//左窗口
        int r = 0;//右窗口
        int sum = nums[l];//加和初始化

        while(l < nums.size())
        {
            if(sum < s && r+1 < nums.size())//当右窗口还能扩展时且加和小于目标值，右窗口扩展
                sum += nums[++r];

            else if(sum >= s)//右窗口无法扩展或者加和大于等于目标值时，先判断不是右窗口到底的情况，再进行左窗口的收缩
            {
                ret = min(ret, (r-l+1));//重新计算最小窗口的长度
                sum -= nums[l++];
            }
            else l++;//右窗口到底，且加和小于目标值，继续收缩左窗口，不进行其他操作
        }
        return ret == begin ? 0 : ret;//根据窗口大小是否被修改过返回相应的值
    }
};

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int min = Solution().minSubArrayLen(7, nums);
    cout<<"min :"<<min<<endl;
    return 0;
}