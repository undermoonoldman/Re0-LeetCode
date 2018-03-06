/**257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]*/

#include <iostream>
#include <vector>
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
private:
    string computePath()//把记录的路径输出成字符串
    {
        string res;
        for(int i = 0 ; i < temp.size()-1 ; i++)
            res = res + temp[i] + "->";
        res = res + temp[temp.size()-1];
        return res;
    }
    vector<string> ret;//返回结果
    vector<string> temp;//用来记录的临时变量

    void helper(TreeNode* root)
    {
        if(root != NULL)//不为空
        {
            temp.push_back(to_string(root->val));//记录当前节点的值
            if(root->left == NULL && root->right == NULL)//是否为叶子节点
            {
                ret.push_back(computePath());//为叶子节点，产生一条记录并存入结果中
                temp.pop_back();//删除最后尝试的路径，为尝试其他路径扫路
                return;
            }
            //不是叶子节点
            helper(root->left);//依次尝试左右路径，深度优先的顺序无所谓
            helper(root->right);
            temp.pop_back();//走到这里说明为非叶子节点，删除当前尝试
        }

        return;//为空，不作事情，结束返回
    }

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        helper(root);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}