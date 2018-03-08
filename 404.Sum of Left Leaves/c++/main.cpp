/*404. Sum of Left Leaves
 * Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/
#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

TreeNode* creatTree()
{
    pNode p1 = new TreeNode(5);
    pNode p2 = new TreeNode(4);
    pNode p3 = new TreeNode(8);
    pNode p4 = new TreeNode(11);
    pNode p5 = new TreeNode(13);
    pNode p6 = new TreeNode(4);
    pNode p7 = new TreeNode(7);
    pNode p8 = new TreeNode(2);
    pNode p9 = new TreeNode(5);
    pNode p10 = new TreeNode(1);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p4->left = p7;
    p4->right = p8;
    p6->left = p9;
    p6->right = p10;
    return p1;
}


class Solution
{
private:
    int sum;

    void helper(TreeNode* root, int tag)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL && tag == 0)
                sum += root->val;
            helper(root->left, 0);
            helper(root->right, 1);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        sum = 0;
        helper(root, 2);
        return sum;
    }
};

int main() {
    TreeNode *p = creatTree();
    int sum = Solution().sumOfLeftLeaves(p);
    cout<<"sum = "<<sum<<endl;
    return 0;
}