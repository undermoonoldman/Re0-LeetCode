/**94. Binary Tree Inorder Traversal
 * Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

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


class Solution//非递归中续遍历
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if(root == NULL)
            return ret;
        //声明一个栈
        stack<TreeNode*> s;//辅助
        TreeNode* p = root;

        while(true)
        {
            if(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                if(s.empty()) break;
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}