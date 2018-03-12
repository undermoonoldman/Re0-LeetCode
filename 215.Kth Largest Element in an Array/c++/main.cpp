/**215. Kth Largest Element in an Array
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int partition(vector<int>&nums, int l, int r)
    {
        srand(time(NULL));//随机选取标定点
        swap(nums[l], nums[rand() % (r-l+1) +l]);
        int tag = l;

        for(int i = l+1 ; i <= r ; i++)
        {
            if(nums[i] > nums[l])
                swap(nums[i], nums[++tag]);
        }
        swap(nums[l], nums[tag]);
        return tag;//返回标定点在数组中的位置，前面为比其大的，后面为比其小的
    }

    int __findKthLargest(vector<int>&nums, int l, int r, int k)
    {
        int p = partition(nums, l, r);//p为第 p+1 大的位置
        if(k == p+1) return nums[p];//找到，返回
        if(k < p+1) return __findKthLargest(nums, l, p-1, k);//在前半段找
        if(k > p+1) return __findKthLargest(nums, p+1, r, k);//在后半段找
    }

public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return  __findKthLargest(nums, 0, nums.size()-1, k);
    }
};

int main()
{
    vector<int>nums = {7,6,5,4,3,2,1};

    int target = Solution().findKthLargest(nums, 2);
    cout<<"target : "<<target<<endl;
    return 0;
}