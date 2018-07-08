/**
 * 563. Binary Tree Tilt
 *
 * Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input:
         1
       /   \
      2     3
Output: 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
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
 * 方法1,2
 * 遍历，对于每个遍历到的结点，先计算坡度，根据定义就是左子树之和与右子树之和的差的绝对值，然后返回的是当前结点的tilt加上对其左右子结点调用求坡度的递归函数即可。
 * 其中求子树之和用另外一个函数来求，也是用遍历来求结点之和，为了避免重复运算，这里用哈希表来保存已经算过的结点
 */


/**
 * 有简化空间
 */
class Solution1 {
private:
    int treeTilt = 0;
    unordered_map<TreeNode*, int> sumed;

    int computeNodeTilt(TreeNode* node){
        if(node->left != NULL && node->right != NULL) return abs(sumNode(node->left) - sumNode(node->right));
        else if(node->left == NULL && node->right == NULL) return 0;
        else if(node->left == NULL) return abs(0 - sumNode(node->right));
        else return abs(sumNode(node->left) - 0);
    }

    int sumNode(TreeNode* root){
        if(root == NULL) return 0;
        if(sumed.count(root) != 0) return sumed[root];
        return sumed[root] = root->val + sumNode(root->left) + sumNode(root->right);
    }

    void inOrder(TreeNode* root){
        if(root != NULL){
            inOrder(root->left);
            treeTilt += computeNodeTilt(root);
            inOrder(root->right);
        }
    }

public:
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        inOrder(root);
        return treeTilt;
    }
};


/**
 * 与方法1本质相同，更简明
 */
class Solution2 {
private:
    unordered_map<TreeNode*, int> sumed;

    int sumNode(TreeNode* root){
        if(root == NULL) return 0;
        if(sumed.count(root) != 0) return sumed[root];
        return sumed[root] = root->val + sumNode(root->left) + sumNode(root->right);
    }

public:
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        int curTilt = abs(sumNode(root->left) - sumNode(root->right));
        return curTilt + findTilt(root->left) + findTilt(root->right);
    }
};

int main() {

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    a->left = b;
    int sum = Solution1().findTilt(a);
    cout<<"sum = "<<sum<<endl;
    return 0;
}