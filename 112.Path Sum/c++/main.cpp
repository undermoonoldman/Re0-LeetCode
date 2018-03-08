/**112. Path Sum
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/
#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

void preOrder(TreeNode* root)
{
    if(root != NULL)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

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
    bool helper(TreeNode* root, int sum)
    {
        if(root->left == NULL && root->right == NULL)
            return root->val == sum;
        else
        {
            bool l = root->left ? helper(root->left, sum - root->val) : false;
            bool r = root->right ? helper(root->right, sum - root->val) : false;
            return l || r;
        }
    }

public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == NULL)
            return false;
        return helper(root, sum);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    TreeNode *p = creatTree();
    bool check = Solution().hasPathSum(p, 26);
    cout<<"check = "<<check<<endl;
    return 0;
}