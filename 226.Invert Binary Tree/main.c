/**226. Invert Binary Tree
 * Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//反转每一个子树，交换其左右孩子节点，直到反转完每一个叶子节点(递归思路)
//类似于层序遍历，先将根节点入队，取出队首，存在左右孩子的话，交换左右孩子后将其入队，直到队列为空(非递归思路)
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}