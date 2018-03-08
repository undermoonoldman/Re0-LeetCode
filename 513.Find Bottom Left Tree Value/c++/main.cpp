/**513. Find Bottom Left Tree Value
 * Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.*/
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
    int findBottomLeftValue(TreeNode* root)
    {
        vector<vector<int>> ret;
        int leftest;
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
            leftest = temp[0];
            temp.clear();
        }
        return leftest;
    }
};

int main() {
    TreeNode *p = creatTree();
    int ret = Solution().findBottomLeftValue(p);
    cout<<"leftest : "<<ret<<endl;
    return 0;
}