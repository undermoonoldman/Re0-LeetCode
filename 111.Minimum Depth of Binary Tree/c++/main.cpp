/**111. Minimum Depth of Binary Tree
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.*/
#include <iostream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution//不能简单的递归，要判读子树为空的情况，与寻找最大高度不一样
{
public:
    int minDepth(TreeNode* root)
    {
        if(root == NULL)//根节点为空返回 0
            return 0;
        if(root->left == NULL)//左子树为空，右子树为不为空都无所谓了
            return 1 + minDepth(root->right);
        if(root->right == NULL)//右子树为空，左子树不为空
            return 1 + minDepth(root->left);

        return min(minDepth(root->right), minDepth(root->left)) + 1;//两子树都不为空，返回深度最小的 + 1
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}