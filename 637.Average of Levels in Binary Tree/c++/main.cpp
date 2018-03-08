/**637. Average of Levels in Binary Tree
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.*/
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

template <typename T>
void showVector(vector<T>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
    {
        cout<<ret[i]<<"  ";
    }
    cout<<endl;
}

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ret;
        if(root == NULL)
            return ret;
        long int temp = 0;
        queue<TreeNode*> store;
        store.push(root);

        while(!store.empty())
        {
            int sz = store.size();
            for(int i = 0 ; i < sz ; i++)
            {
                temp += store.front()->val;
                if(store.front()->left)
                    store.push(store.front()->left);
                if(store.front()->right)
                    store.push(store.front()->right);
                store.pop();
            }
            double avarage = (double)temp / sz;
            ret.push_back(avarage);
            temp = 0;
        }
        return ret;
    }
};

int main() {
    TreeNode *p = creatTree();
    vector<double> ret = Solution().averageOfLevels(p);
    showVector(ret);
    return 0;
}