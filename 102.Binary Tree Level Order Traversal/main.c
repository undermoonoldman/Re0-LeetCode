/**102. Binary Tree Level Order Traversal
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]*/


/**

 */
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

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

void traverseQueue(pQueue pQ)//遍历队列
{
    pNode p = pQ->front;
    if(pQ->front == NULL)
        printf("is empty\n");
    while(p != NULL)
    {
        printf("%d -> ",p->value->val);
        p = p->next;
        if(p == NULL)
            printf("NULL\n");
    }
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if(root == NULL)
        return NULL;
    *returnSize = 0;
    int result[50000];//储存层序遍历的结果
    int colSz[2000];//储存层序遍历每一层的节点数目
    int countNum = 0;//记录所遍历过节点的个数
    int countCol = 0;//记录所遍历过的层数
    pQueue pQ = createQueue();//初始化队列
    insert(pQ, root);//插入根节点
    while(pQ->front != NULL)//循环出队，直到队列为空
    {
        int tempSz = pQ->size;//每次循环取得队列的大小，即为二叉树每层的节点的个数
        colSz[countCol++] = tempSz;//记录每层的节点个数
        for(int i = 0 ; i < tempSz ; i++)//把每层的所有节点进行出队，把它们的子节点(也就是下一层节点)入队，这样队列中就全部为下一层的节点了
        {
            result[countNum++] = front(pQ)->val;//每次出队，记录遍历过的节点的个数
            if(front(pQ)->left != NULL)//入队左孩子
                insert(pQ, front(pQ)->left);
            if(front(pQ)->right != NULL)//入队右孩子
                insert(pQ, front(pQ)->right);
            extract(pQ);//移除队首节点
        }
    }

    *columnSizes = (int*)malloc(sizeof(int) * countCol);//*columnSizes 可以用数组赋值
    int* colu = (int*)malloc(sizeof(int) * countCol);

    for(int i = 0 ; i < countCol ; i++)
        colu[i] = colSz[i];//用 colu 取得 colSz 中有赋值的部分

    *columnSizes = colu;
    *returnSize = countCol;
    int count = 0;
    int** ret = (int**)malloc(sizeof(int*) * countCol);//返回的数组集合
    for(int i = 0 ; i < countCol ; i++)//每一层储存到一个数组中
    {
        int sz = columnSizes[0][i];
        int* temp = (int*)malloc(sizeof(int) * sz);
        for(int j = 0 ; j < sz ; j++)
            temp[j] = result[count++];

        ret[i] = temp;
    }
    return ret;
}



#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    pTnode p = createTree();
    int *returnSize = (int*)malloc(sizeof(int));
    int *array;
    int **columnSizes = &array;
    int **ret = levelOrder(p, columnSizes, returnSize);
    printf("%d %d %d %d %d\n",ret[0][0],ret[1][0],ret[1][1],ret[2][0], ret[2][1]);
    return 0;
}