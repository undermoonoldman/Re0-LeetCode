/**349. Intersection of Two Arrays
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> set1(nums1.begin(), nums1.end());//直接使用构造函数比一个个的插入效率高
        set<int> set2;

        for(int i : nums2)
            if(set1.find(i) != set1.end())
                set2.insert(i);

        return vector<int>(set2.begin(), set2.end());//使用构造函数比遍历取出效率高
    }
};

void showVector(vector<int> ret)
{
    for(int i : ret)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ret = Solution().intersection(num1, nums2);
    showVector(ret);
    return 0;
}