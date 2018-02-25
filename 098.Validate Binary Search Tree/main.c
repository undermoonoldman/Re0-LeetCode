#include <stdbool.h>
#include <stdlib.h>

/**98. Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.*/


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode *pNode, Node;

pNode createTree()
{
    pNode p1 = (pNode)malloc(sizeof(Node));
    p1->val = 0;
    p1->left = NULL;
    p1->right = NULL;

    return p1;
}


///全局指针变量会自己初始化为 NULL
struct TreeNode* lastNode;//全局变量，用于记录上次访问过的节点

bool __isValidBST(struct TreeNode* root)
{
    if(root == NULL)//为空，返回 true
        return true;
    if(!__isValidBST(root->left))//递归访问左子树(访问到叶子节点的左孩子时会返回 true 结束递归)
        return false;
    if(lastNode != NULL)//存在上次访问的节点记录(非最小节点的访问)
    {
        if(lastNode->val >= root->val)//对比值的大小，确定升序序列
            return false;
    }
    lastNode = root;//更新上次访问节点的记录
    return __isValidBST(root->right);//递归访问右子树
}

//二叉搜索树中序遍历为升序序列，如果出现降序序列，说明非二叉搜索树
bool isValidBST(struct TreeNode* root)
{
    lastNode = NULL;//再一次初始化全局变量,leetcode编译器不能很好的执行全局指针变量初始化为 NULL
    return __isValidBST(root);
}


#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    pNode p = createTree();
    bool check = isValidBST(p);
    printf("the value of check is %d\n",check);

    return 0;
}