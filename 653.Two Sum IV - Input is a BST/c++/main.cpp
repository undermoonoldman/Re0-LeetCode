/**653. Two Sum IV - Input is a BST
 * Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

TreeNode* creatTree()
{
    pNode p1 = new TreeNode(5);
    pNode p2 = new TreeNode(3);
    pNode p3 = new TreeNode(6);
    pNode p4 = new TreeNode(2);
    pNode p5 = new TreeNode(4);
    pNode p6 = new TreeNode(7);


    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p5;
    p3->right = p6;

    return p1;
}

class Solution
{
private:
    void helper(TreeNode* root, vector<int>& res)
    {
        if(root != NULL)
        {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }

public:
    bool findTarget(TreeNode* root, int k)//bst中序遍历形成有序数组，然后对有序数组进行 2SUM
    {
        vector<int> res;
        helper(root, res);
        int l = 0;
        int r = res.size() - 1;
        while(l < r)
        {
            if(res[l] + res[r] == k)
                return true;
            if(res[l] + res[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};

int main() {
    TreeNode* p = creatTree();
    bool check = Solution().findTarget(p, 9);
    cout<<"check is : "<<check<<endl;
    return 0;
}