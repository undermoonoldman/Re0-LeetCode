/**
 * 100. Same Tree
 *
 * Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ////两结点都为空，是同一颗树
        if(p == NULL && q == NULL) return true;
        ////有一个结点为空，不是同一颗树
        if(p == NULL || q == NULL) return false;
        ////两结点值不相同，不是同一颗树
        if(p->val != q->val) return false;
        ////两结点值相同，还需要他们的左右子树也相同，才是同一颗树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}