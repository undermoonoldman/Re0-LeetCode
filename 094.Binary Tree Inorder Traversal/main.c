/**94. Binary Tree Inorder Traversal
 * Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

    struct TreeNode
    {
            int val;
            struct TreeNode *left;
            struct TreeNode *right;
    };

void computeNodes(struct TreeNode* root, int* returnSize)
{
    if(root != NULL)
    {
        computeNodes(root->left, returnSize);
        *returnSize = *returnSize + 1;
        computeNodes(root->right, returnSize);
    }
    else
        return;
}

void __inorderTraversal(struct TreeNode* root, int* ret, int* count)
{
    if(root != NULL)
    {
        __inorderTraversal(root->left, ret, count);
        ret[*count] = root->val;
        *count = *count + 1;
        __inorderTraversal(root->right, ret, count);
    }
    else
        return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    computeNodes(root, returnSize);
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    int* count = (int*)malloc(sizeof(int));
    *count = 0;
    __inorderTraversal(root, ret, count);
    return ret;
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}