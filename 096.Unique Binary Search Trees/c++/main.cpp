/*96. Unique Binary Search Trees
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> used;

    void generatePossible(int n, int step)
    {
        if(step == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(used[i-1] == true) continue;
            used[i-1] = true;
            temp.push_back(i);
            generatePossible(n, step-1);
            used[i-1] = false;
            temp.pop_back();
        }
    }

    bool checkBST(vector<int> nums)
    {
        if(nums.size() <= 2)
            return true;

        int root = nums[0];
        int flag;//0只有左子树，1只有右子树，2左右子树都有
        int l = 1;
        int r = nums.size()-1;
        if(nums[l] < root && nums[r] < root)
            flag = 0;
        else if(nums[l] > root && nums[r] > root)
            flag = 1;
        else
            flag = 2;

        vector<int> left;
        vector<int> right;

        if(flag == 0)
        {
            for(int i = l ; i <= r ; i++)
            {
                if(nums[i] < root)
                    left.push_back(nums[i]);
                else
                    return false;
            }
        }
        else if(flag == 1)
        {
            for(int i = l ; i <= r ; i++)
            {
                if(nums[i] > root)
                    right.push_back(nums[i]);
                else
                    return false;
            }
        }
        else
        {
            int tag;
            for(int i = l ; i <= r ; i++)
            {
                tag = i;
                if(nums[i] < root)
                    left.push_back(nums[i]);
                else
                    break;
            }

            for(int i = tag ; i <= r ; i++)
            {
                if(nums[i] > root)
                    right.push_back(nums[i]);
                else
                    return false;
            }
        }
        return checkBST(left) && checkBST(right);

    }

    int countBST()
    {
        int count = 0;
        for(vector<int> i : res)
            if(checkBST(i)) count++;
        return count;
    }

public:
    int numTrees(int n)
    {
        if(n <= 2)
            return n;
        used = vector<bool>(n, false);
        generatePossible(n, n);
        return countBST();
    }
};

int main()
{
    int count = Solution().numTrees(4);
    cout<<"count : "<<count<<endl;
    return 0;
}