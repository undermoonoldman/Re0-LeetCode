/**47. Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]*/

#include <iostream>
#include <vector>
using namespace std;

void show(vector<int>& temp)
{
    for(int i = 0 ; i < temp.size() ; i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}

void showVector(vector<vector<int>>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";

        cout<<endl;
    }
}

class Solution//搜索空间有序，有重复。搜索可以降序，并减去对相同分支子树的搜索. 例如：[1,1,2] 中，第一个 1 与第二个 1 不用重复搜索，只搜索相同子树中的第一个
{
private:
    vector<bool> used;

    void helper(vector<vector<int>>&ret, vector<int>& p, vector<int>& nums, int step)
    {
        if(step == nums.size())
        {
            ret.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!used[i])
            {
                /**A. nums[i-1]是上次搜索的节点，nums[i]是本次搜索的节点，nums[i]为上次搜索的节点，在对一颗子树进行搜索时，这两个节点分别位于上下两层，这时它们的值可以重复因为给定的搜索空间是有重复的
                 *B. 但是若两节点位于同一层属于兄弟的话，这时它们的值重复的话就只搜索一边就行了，例如:[1,1,2]中，左孩子会产生 1,1,2 中孩子也会产生 1,1,2 所以中孩子不用进行搜索了
                 *C .如何判断先后两节点值相同时属于同一层还是上下曾呢，是上下层的话，上层已经被标记为 used 了，而同层的话，在搜索后节点时，现会对前节点解除 used 标记
                 *D .故 used[i-1] 为假，说明是同层， used[i-1] 为真，说明是上下层*/
                if(i != 0 && !used[i-1] && nums[i] == nums[i-1]) continue;
                used[i] = true;//进入子树分支前标记以占用的分支
                p.push_back(nums[i]);

                helper(ret, p, nums, step+1);
                used[i] = false;
                p.pop_back();
            }

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());//先排序，使搜索空间有序

        helper(ret, temp, nums, 0);
        return ret;
    }
};


int main()
{
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(1);
    candidates.push_back(2);
    vector<vector<int>> ret = Solution().permuteUnique(candidates);
    cout<<"result is : \n";
    showVector(ret);
    return 0;
}