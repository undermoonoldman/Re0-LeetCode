/**110. Balanced Binary Tree
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.*/
#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

class Solution
{
private:

    int maxDepth(TreeNode* root)//方法 B : 递归，深度优先遍历
    {
        if(root == NULL)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    bool helper(TreeNode* root)
    {
        if(root == NULL) return true;
        int lMax = maxDepth(root->left);

        int rMax = maxDepth(root->right);

        if(abs(lMax-rMax) > 1)//左右子树最大高度差不超过 1
            return false;

        return helper(root->left) && helper(root->right);//根节点平衡后，对左右孩子进行平衡检查
    }

public:

    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)//空树，平衡
            return true;
        return helper(root);
    }
};


int main()
{

    return 0;
}