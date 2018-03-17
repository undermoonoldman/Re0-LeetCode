/**350. Intersection of Two Arrays II
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        unordered_map<int, int> map1;//统计nums1的频次,使用unorder_map 底层为hashmap比map更快，查找为 O(1), map查找为 O(logN)


        for(int i : nums1)
            map1[i]++;
        for(int i : nums2)
        {
            if(map1[i] != 0)//找到相同元素
            {
                res.push_back(i);
                map1[i]--;//更改频次
            }
        }


        return res;
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
    vector<int> num1 = {1};
    vector<int> nums2 = {1, 1};
    vector<int> ret = Solution().intersect(num1, nums2);
    showVector(ret);
    return 0;
}