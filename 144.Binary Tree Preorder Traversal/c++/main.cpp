/**144. Binary Tree Preorder Traversal
 * Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

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


class Solution//非递归前续遍历
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if(root == NULL)
            return ret;
        //声明一个栈
        stack<TreeNode*> s;//辅助

        s.push(root);//根节点入栈

        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();
            ret.push_back(p->val);
            if(p->right != NULL)
                s.push(p->right);//先压入右孩子，这样每次取出的都是左孩子(如果存在的话)。
            if(p->left != NULL)
                s.push(p->left);
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}