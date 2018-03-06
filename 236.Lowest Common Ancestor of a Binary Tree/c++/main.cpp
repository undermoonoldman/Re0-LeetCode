/**236. Lowest Common Ancestor of a Binary Tree
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.*/
#include <iostream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || p == root || q == root) return root;//如果根节点为空，或者要找的某一个节点为根节点的话，返回根节点
        TreeNode* l = lowestCommonAncestor(root->left, p, q);//在左子树中找两个节点
        TreeNode* r = lowestCommonAncestor(root->right, p, q);//在右子树中找两个节点
        if(l != NULL && r != NULL)//都有找到，说明两个节点分布左右两个子树上，根节点为公共祖先
            return root;
        return l == NULL ? r : l;//如果两节点在一颗子树上，返回的肯定只有一个为空
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}