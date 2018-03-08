/**113. Path Sum II
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]*/

#include <iostream>
#include <vector>
using namespace std;


void show(vector<int>& temp)
{
    for(int i = 0 ; i < temp.size() ; i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}

void showVector(vector<vector<int>>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";

        cout<<endl;
    }
}

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


/**搜索空间为两个(左右子树),搜索顺序，无所谓*/
class Solution
{
private:

    void helper(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int>&temp)
    {
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)//递归终止条件，为叶子节点
        {
            if(sum == root->val)
                ret.push_back(temp);
            return;
        }

        if(root->left != NULL)
        {
            helper(root->left, sum - root->val, ret, temp);
            temp.pop_back();//进行了一次尝试无论失败都要退出当前值
        }

        if(root->right != NULL)
        {
            helper(root->right, sum - root->val, ret, temp);
            temp.pop_back();//进行了一次尝试无论失败都要退出当前值
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        if(root == NULL)
            return ret;
        helper(root, sum, ret, temp);
        return ret;
    }
};


int main() {
    TreeNode *p = creatTree();
    vector<vector<int>> ret = Solution().pathSum(p, 22);
    showVector(ret);
    return 0;
}