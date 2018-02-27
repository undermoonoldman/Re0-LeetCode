#include <stdlib.h>

/**114. Flatten Binary Tree to Linked List
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 */


struct TreeNode//二叉树节点
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode treeNode, *pTnode;

void preOrder(struct TreeNode* root)
{
    if(root != NULL)
    {
        printf("%d -- ",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void rightOrder(struct TreeNode* root)
{
    if(root != NULL)
    {
        printf("%d ... ",root->val);
        rightOrder(root->right);
    }
}

pTnode createTree()//创立二叉树
{
    pTnode p1 = (pTnode)malloc(sizeof(treeNode));
    pTnode p2 = (pTnode)malloc(sizeof(treeNode));
    pTnode p3 = (pTnode)malloc(sizeof(treeNode));
    pTnode p4 = (pTnode)malloc(sizeof(treeNode));
    pTnode p5 = (pTnode)malloc(sizeof(treeNode));
    p1->val = 3;
    p1->left = p3;
    p1->right = p5;
    p2->val = 7;
    p2->left = NULL;
    p2->right = NULL;
    p3->val = 9;
    p3->left = NULL;
    p3->right = NULL;
    p4->val = 15;
    p4->left = NULL;
    p4->right = NULL;
    p5->val = 20;
    p5->left = p4;
    p5->right = p2;

    return p1;
}

struct TreeNode* last;

void __flatten(struct TreeNode* root)
{
    if(root != NULL)
    {
        if(last != NULL)
            (last)->left = root;

        last = root;

        __flatten(root->left);
        __flatten(root->right);

    }
}

void __linked(struct TreeNode* root, struct TreeNode* last)
{
    if(root != NULL)
    {
        (last)->right = root->left;
        (last) = (last)->right;
        struct TreeNode* temp = root->left;
        root->left = NULL;
        __linked(temp, last);
    }
}


/**算法要求原地，不能创建链表，看示例可以观察到，二叉树生成的链表顺序其实是前序遍历的顺序
思路1：前序遍历的叶子节点的左孩子其实没有指向，这里可以利用遍历序列的左孩子来指向下一个要遍历的节点，这样经过一次前序遍历就把树变成了一个左偏
的链表，在对这个链表进行一遍遍历把左偏改为右偏*/
void flatten(struct TreeNode* root)
{
    if(root == NULL)
        return;
    last = NULL;//全局遍历初始化

    __flatten(root);//变为左偏链表

    last = root;
    __linked(root, last);//变为右偏链表
}


#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    pTnode tree = createTree();
    printf("preOrder: ");
    preOrder(tree);
    flatten(tree);
    printf("\n");
    printf("rightOrder: ");
    rightOrder(tree);
    return 0;
}