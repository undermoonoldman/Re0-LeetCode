/**199. Binary Tree Right Side View
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].*/

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

void showVector(vector<int>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
        cout<<ret[i]<<"  ";
    cout<<endl;
}

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ret;
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
            ret.push_back(temp[temp.size()-1]);
            temp.clear();
        }
        return ret;
    }
};

int main() {
    TreeNode *p = creatTree();
    vector<int> ret = Solution().rightSideView(p);
    showVector(ret);
    return 0;
}