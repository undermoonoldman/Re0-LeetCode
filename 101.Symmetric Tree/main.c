#include <stdbool.h>

/**101. Symmetric Tree
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.*/


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasSameValue(struct TreeNode* l, struct TreeNode* r)
{
    if(l == NULL && r == NULL)//左右子树都为空，对称
        return true;
    if(l == NULL || r == NULL)//有一个为空，不对称
        return false;
    if(l->val == r->val)//值相等，再检查子树
        return hasSameValue(l->left, r->right) && hasSameValue(l->right, r->left);
    return false;//值不相等，不对称
}


/**又是一个递归题，判断树为轴对称，左子树的左子树等于右子树的右子树，左子树的右子树等于右子树的左子树*/
bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)//根为空，为对称
        return true;
    return hasSameValue(root->left, root->right);
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}