/**
 * 669. Trim a Binary Search Tree
 *
 * Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
    1
   / \
  0   2

  L = 1
  R = 2

Output:
    1
      \
       2
Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output:
      3
     /
   2
  /
 1
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 三种情况，根小于最小值，根据BST的特性，减掉根节点与左枝，根结点变为对右子树进行剪枝的结果
 * 根大于最大值，减掉根结点与右枝，根结点变为对左子树进行剪枝的结果
 * 根结点处于区间内，递归的对左右子树进行剪枝
 */

class Solution {
public:
    // No cleanup -> memory leak
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        // val not in range, return the left/right subtrees
        if(root->val < L) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        // val in [L, R], recusively trim left/right subtrees
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}