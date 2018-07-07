/**617. Merge Two Binary Trees
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7*/
#include <iostream>

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

class Solution1//贼j8经典的递归，记住, 直接在原来的树上面进行更改
{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

class Solution2 //重新构建一棵树
{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root = __mergeTrees(t1, t2);
        return root;
    }


private:
    TreeNode* __merge(TreeNode* t1, TreeNode* t2)//拼装新的结点
    {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        if(t1 == NULL)
            return new TreeNode(t2->val);
        if(t2 == NULL)
            return new TreeNode(t1->val);
        return new TreeNode(t1->val + t2->val);
    }

    TreeNode* __mergeTrees(TreeNode* t1, TreeNode* t2)//归并两个树，返回新生成的树的根结点
    {
        TreeNode* root = __merge(t1, t2);//创建新树的根结点
        if(!(t1 == NULL && t2 == NULL))//深度优先遍历创建新树的左右孩子结点，当要归并的两部分都为空时不在往下进行了
        {
            root->left = __mergeTrees(t1 == NULL ? t1 : t1->left, t2 == NULL ? t2 : t2->left);//有一边能遍历下去就继续进行
            root->right = __mergeTrees(t1 == NULL ? t1 :t1->right, t2 == NULL ? t2 :t2->right);
        }
        return root;//返回新的根节点
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}