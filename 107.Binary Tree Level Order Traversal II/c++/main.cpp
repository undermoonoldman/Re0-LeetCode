/**107. Binary Tree Level Order Traversal II
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]*/

#include <iostream>
#include <vector>
#include <queue>
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

void showVector(vector<vector<int>>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        for(int j = 0 ; j < ret[i].size() ; j++)
            cout<<ret[i][j]<<"  ";

        cout<<endl;
    }
}

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        vector<int> temp;
        queue<TreeNode*> store;
        store.push(root);

        while(!store.empty())
        {
            int sz = store.size();
            for(int i = 0 ; i < sz ; i++)
            {
                temp.push_back(store.front()->val);
                if(store.front()->left)
                    store.push(store.front()->left);
                if(store.front()->right)
                    store.push(store.front()->right);
                store.pop();
            }
            ret.push_back(temp);
            temp.clear();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    TreeNode *p = creatTree();
    vector<vector<int>> ret = Solution().levelOrderBottom(p);
    showVector(ret);
    return 0;
}