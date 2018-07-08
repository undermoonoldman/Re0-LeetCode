/**
 * 543. Diameter of Binary Tree
 *
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.


 */
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 计算某棵书的 diameter 值分两种情况，diameter 过根节点与不过根节点，过根节点的情况，计算根节点左右子树最大高度的和即为 diameter
 * 不过根节点，需要分别计算左右两棵子树的 diameter 值，从中取得最大值，
 * 综上 diameter(root) = max(maxHeight(root->left) + maxHeight(root->right), max(diameter(root->left), diameter(root->right)))
 * 可见这是一个递归定义，在计算过程中要重复计算很多次树高度与树的 diameter 值，所以采用记忆化搜索对计算过的值进行存储
 */
class Solution {
private:
    unordered_map<TreeNode*, int> diameter;////存储计算过的 diameter 值
    unordered_map<TreeNode*, int> height;////存储计算过的 height of tree

    /**
     * 计算树高
     * @param root
     * @return
     */
    int treeHeight(TreeNode* root){
        if(root == NULL) return 0;
        if(height.count(root) != 0) return height[root];
        return height[root] = max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        if(diameter.count(root) != 0) return diameter[root];

        int lHeight = treeHeight(root->left);//左子树高
        int rHeight = treeHeight(root->right);//右子树高
        int rootDiameter = lHeight + rHeight;//过根节点的 diameter 值
        int lDiameter = diameterOfBinaryTree(root->left);//左子树 diameter 值
        int rDiameter = diameterOfBinaryTree(root->right);//右子树 diameter 值
        int ret = max(rootDiameter, max(lDiameter, rDiameter));//计算得到最终 diameter 值
        return diameter[root] = ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}