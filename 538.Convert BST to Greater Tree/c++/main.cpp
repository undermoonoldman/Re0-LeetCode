/**
 * 538. Convert BST to Greater Tree
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

/**
 * 方法1
 * 第一遍中序遍历，排出一个从小到大的顺序表
 * 第二遍中序遍历，根据顺序表，对结点进行累加
 * o(n) * 2，两边遍历
 */
class Solution1 {
private:
    vector<int> ordered;//顺序表
    int index = 0;//累加位置标记

    ////从小到大遍历
    void inOrder(TreeNode* root){
        if(root != NULL){
            inOrder(root->left);
            ordered.push_back(root->val);
            inOrder(root->right);
        }
    }

    void greater(TreeNode* root){
        if(root != NULL){
            greater(root->left);
            for(int i = index+1 ; i < ordered.size() ; i++)
                root->val += ordered[i];
            index++;
            greater(root->right);
        }
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        greater(root);
        return root;
    }
};

/**
 * 方法2
 * 右根左遍历，从大到小，最大的结点累加值为零，后面遍历到的结点累加它的前驱结点值就行了
 *
 * o(n) 一遍遍历
 */
class Solution2 {
private:
    int sum = 0;//类加值记录，初始化为零

    ////从大到小遍历
    void greater(TreeNode* root)
    {
        if(root != NULL){
            greater(root->right);
            root->val += sum;
            sum = root->val;
            greater(root->left);
        }
    }


public:
    TreeNode* convertBST(TreeNode* root) {
        greater(root);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}