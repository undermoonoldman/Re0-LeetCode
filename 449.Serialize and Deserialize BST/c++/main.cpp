/**449. Serialize and Deserialize BST
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void showVector(vector<T>& ret)
{
    for(int i = 0 ; i < ret.size() ; i++)
        cout<<ret[i]<<" ";

    cout<<endl;

}



typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*pNode;

void inOrder(TreeNode* root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

TreeNode* creatTree()
{
    pNode p1 = new TreeNode(5);
    pNode p2 = new TreeNode(3);
    pNode p3 = new TreeNode(6);
    pNode p4 = new TreeNode(2);
    pNode p5 = new TreeNode(4);
    pNode p6 = new TreeNode(7);


    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    return p1;
}

class Codec//与普通二叉树的做法有较大的不同，BST能通过前序遍历构造整颗二叉树(头部为根节点，比起值小的为左子树，比其值大的为右子树，这样递归构造就可以了)
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)//这里采用了前序遍历的方式，而且不处理空的问题，只记录有值的节点
    {
        if(root == NULL)//特殊情况处理
            return "";
        string ret;//返回的序列化结果
        stack<TreeNode*> res;
        TreeNode *p = root;
        res.push(root);

        while(!res.empty())
        {
            p = res.top();
            ret += to_string(p->val);
            ret += ",";
            res.pop();
            if(p->right)
                res.push(p->right);
            if(p->left)
                res.push(p->left);
        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)//非空标记为 null , 节点间的间隔标记为 ","
    {
        if(data == "")//特殊情况处理
            return NULL;
        vector<string> res;

        //以"," 为切分，找到每个节点对应的子串，存到 vector中
        int last = 0;
        int index = data.find(',', 0);
        while(last < data.size())
        {
            string temp = data.substr(last, index-last);
            res.push_back(temp);
            last = index + 1;
            index = data.find(',', last);
        }

        //showVector(res);
        queue<TreeNode*> line;//辅助用的队列

        for(string i : res)//把前序遍历的节点按顺序入队
        {
            TreeNode *p = new TreeNode(atoi(i.c_str()));
            line.push(p);
        }

        return getNode(line);//根据队列构造BST
    }

    TreeNode* getNode(queue<TreeNode*> line)
    {
        if(line.empty()) return NULL;
        TreeNode *root = new TreeNode(line.front()->val);//根节点为首部
        line.pop();//pop掉根节点之后，line 队列中就只剩下左子树，与右子树了
        queue<TreeNode*> leftChild;//保存左孩子的队列

        while(!line.empty() && line.front()->val < root->val)//取出左子树，line队列就成为了只保存右子树的队列
        {
            leftChild.push(line.front());
            line.pop();
        }

        root->left = getNode(leftChild);//递归构造左子树

        root->right = getNode(line);//递归构造右子树

        return root;
    }
};

int main()
{
    TreeNode *p = creatTree();
    inOrder(p);
    cout<<endl;
    string res = Codec().serialize(p);
    cout<<"res : "<<res<<endl;
    cout<<endl;
    TreeNode *q = Codec().deserialize("5,3,2,4,6,7,");
    inOrder(q);
    return 0;
}