/**220. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution//在区间范围相差 k 以内中找到两值相差不超过 t 的两数
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<long long> been;//底层为二叉树的 set 能找到大于某值的最小值 ceil
        for(int i = 0 ; i < nums.size() ; i++)//当固定了一个数 nums[i] 后，如果能在区间 k 内找到 num[i]-t ~ nums[i]+t 范围的值，就返回 true
        {//大于 nums[i]-t 的最小值小于 nums[i]+t
            if( been.lower_bound( (long long)nums[i] - (long long)t ) != been.end() &&
                *been.lower_bound( (long long)nums[i] - (long long)t ) <= (long long)nums[i] + (long long)t )
                return true;

            been.insert(nums[i]);
            if(been.size() > k)
                been.erase(nums[i-k]);
        }
        return false;
    }
};

int main()
{
    int nums[] = {-2147483648,-2147483647};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 3;
    int t = 3;

    if( Solution().containsNearbyAlmostDuplicate(vec, k, t) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}