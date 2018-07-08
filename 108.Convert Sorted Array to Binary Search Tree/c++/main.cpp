/**
 * 108. Convert Sorted Array to Binary Search Tree
 *
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
 * 二分法构造，先构造根结点，mid 处，再递归构建左右子树，l - mid-1 与 mid+1 - r 处
 */
class Solution {
private:
    TreeNode* buildTree(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int mid = (r - l) / 2 + l;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid-1);
        root->right = buildTree(nums, mid+1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}