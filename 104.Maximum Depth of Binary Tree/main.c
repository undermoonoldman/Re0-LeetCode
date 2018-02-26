#include <stdlib.h>
#include <assert.h>
/**104. Maximum Depth of Binary Tree
 * Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.*/

int max(int a, int b)
{
    return a > b ? a : b;
}

struct TreeNode//二叉树节点
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode treeNode, *pTnode;

pTnode createTreeNode(int value)//传入整数值创立二叉树节点
{
    pTnode ptn = (pTnode)malloc(sizeof(treeNode));
    ptn->val = value;
    ptn->right = NULL;
    ptn->left = NULL;
    return ptn;
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

typedef struct Node//队列节点定义
{
    pTnode value;

    struct Node* next;
}Node, *pNode;

pNode createNode(pTnode ptn)//根据二叉树节点创立队列节点
{
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    p->value = ptn;
    return p;
}

typedef struct Queue//队列定义
{
    pNode front;
    pNode rear;
    int size;
}Queue, *pQueue;

pQueue createQueue()//创建初始化队列
{
    pQueue p = (pQueue)malloc(sizeof(Queue));
    p->front = NULL;
    p->rear = NULL;
    p->size = 0;
    return p;
}

void insert(pQueue pQ,pTnode ptn)//把二叉树节点插入队列
{
    if(pQ->front == NULL && pQ->rear == NULL)
    {
        pNode temp = createNode(ptn);
        pQ->front = temp;
        pQ->rear = temp;
        pQ->size++;
    }
    else
    {
        pNode temp = createNode(ptn);
        pQ->rear->next = temp;
        pQ->rear = temp;
        pQ->size++;
    }
}

pTnode front(pQueue pQ)//取得队列首部的二叉树节点，不删除
{
    assert(pQ->front != NULL);
    return pQ->front->value;
}

pTnode extract(pQueue pQ)//取得队列首部的二叉树节点，并删除
{
    assert(pQ->front != NULL);
    pTnode ret = pQ->front->value;
    pQ->front = pQ->front->next;
    pQ->size--;
    return ret;
}

int size(pQueue pQ)//获取队列中元素的个数
{
    return pQ->size;
}

int maxDepth(struct TreeNode* root)//方法 A : 广度优先层序遍历
{
    if(root == NULL)
        return 0;
    int colSz[2000];//储存层序遍历每一层的节点数目
    int countCol = 0;//记录所遍历过的层数
    pQueue pQ = createQueue();//初始化队列
    insert(pQ, root);//插入根节点
    while(pQ->front != NULL)//循环出队，直到队列为空
    {
        int tempSz = pQ->size;//每次循环取得队列的大小，即为二叉树每层的节点的个数
        colSz[countCol++] = tempSz;//记录每层的节点个数
        for(int i = 0 ; i < tempSz ; i++)//把每层的所有节点进行出队，把它们的子节点(也就是下一层节点)入队，这样队列中就全部为下一层的节点了
        {
            if(front(pQ)->left != NULL)//入队左孩子
                insert(pQ, front(pQ)->left);
            if(front(pQ)->right != NULL)//入队右孩子
                insert(pQ, front(pQ)->right);
            extract(pQ);//移除队首节点
        }
    }

    return countCol;
}


//int maxDepth(struct TreeNode* root)//方法 B : 递归，深度优先遍历
//{
//    if(root == NULL)
//        return 0;
//    else
//        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//}


#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    pTnode p = createTree();
    int depth = maxDepth(p);
    printf("max depth is %d\n",depth);
    return 0;
}