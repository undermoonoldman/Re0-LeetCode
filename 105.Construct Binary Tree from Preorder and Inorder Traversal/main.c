#include <stdlib.h>
#include <assert.h>

/**105. Construct Binary Tree from Preorder and Inorder Traversal
 * Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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

void postOrder(struct TreeNode* root)//后序遍历测试用
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d -- ",root->val);
    }
}

//利用前序遍历可以方便的找到根节点，中序遍历在已知根节点位置的情况下可以吧序列切分成，左子树，根节点，右子树.三部分
/**helpBuild 函数取前序中序两数组与一组范围约束，返回以该约束生成的二叉树的根节点
 * 约束条件 inSt : 中序起始点   inEn : 中序结束点
 * preSt : 前序起始点
 * 隐藏约束条件 preEn : 前序结束点
 * 1. 每次的 preSt 都为查找子树片段的根节点，因为节点的值不重复，根据该值在中序序列中找到根节点对应的位置 temp
 * 2. 根据中序找到根节点的位置 temp 对中序片段进行切分，inSt - temp-1 为左子树的片段，temp+1 - inEn 为右子树的片段.
 * 3. 而前序序列中，左子树的根为 preSt+1 ，右子树的根为 preSt+(temp-inSt+1) ，因为前序遍历可以切分为两部分，A:根节点与左子树，B:右子树*/
struct TreeNode* helpBuild(int* preorder, int preorderSize, int* inorder, int inorderSize, int preSt, int inSt, int inEn)
{
    if(preSt > preorderSize || inSt > inEn)//出界情况
        return NULL;
    pTnode current = createTreeNode(preorder[preSt]);//根据值构造节点
    int temp = inSt;
    for(int i = temp ; i <= inEn ; i++)//找到中序根节点的位置
    {
        if(inorder[i] == preorder[preSt])
        {
            temp = i;
            break;
        }
    }
    current->left = helpBuild(preorder, preorderSize, inorder, inorderSize, preSt+1, inSt, temp-1);//递归构造左子树，参数有变
    current->right = helpBuild(preorder, preorderSize, inorder, inorderSize, preSt+(temp-inSt+1), temp+1, inEn);//递归构造右子树，参数有变
    return current;//返回根
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize == 0)
        return NULL;
    struct TreeNode* root = helpBuild(preorder, preorderSize, inorder, inorderSize, 0, 0, preorderSize-1);//初始边界的确立
    return root;
}

#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    int a[] = {3,9,20,15,7};
    int b[] = {9,3,15,20,7};
    pTnode root = buildTree(a, 5, b, 5);
    postOrder(root);
    return 0;
}