/**145. Binary Tree Postorder Traversal
 * Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3


return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution//非递归后续遍历
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if(root == NULL)
            return ret;
        //声明两个栈
        stack<TreeNode*> s1;//辅助
        stack<TreeNode*> s2;//储存遍历序列
        s1.push(root);//根节点入左栈

        while(!s1.empty())
        {
            TreeNode* p = s1.top();
            s1.pop();
            s2.push(p);
            if(p->left != NULL)
                s1.push(p->left);
            if(p->right != NULL)
                s1.push(p->right);
        }

        while(!s2.empty())
        {
            ret.push_back(s2.top()->val);
            s2.pop();
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}