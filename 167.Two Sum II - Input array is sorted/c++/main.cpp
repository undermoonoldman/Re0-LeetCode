/**167. Two Sum II - Input array is sorted
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> ret;
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                ret.push_back(l+1);
                ret.push_back(r+1);
                break;
            }
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}