/**297. Serialize and Deserialize Binary Tree
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.*/
#include <iostream>
#include <vector>
#include <queue>

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

void preOrder(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
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

class Codec//超级重要的题
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)//类似于层序遍历，区别是，层序遍历不加入空节点，而序列化加入空节点，这样当队列中取出空节点时就可以添加空节点标记了
    {
        if(root == NULL)//特殊情况处理
            return "";
        string ret;//返回的序列化结果

        queue<TreeNode*> store;
        store.push(root);

        while(!store.empty())
        {
            TreeNode *p = store.front();
            store.pop();
            if (p == NULL)//取出节点为空，序列中添加为空标记 null,不进行子树的添加，跳过
            {
                ret += "null,";
                continue;
            }
            ret += to_string(p->val);//取出节点不为空，添加值，并把子树添加到队列中(无论子树是否存在)
            ret += ",";
            store.push(p->left);
            store.push(p->right);
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

        TreeNode *root = new TreeNode(atoi(res[0].c_str()));//根节点对应的串在 vector 首部，根据串转换为的整数值构造根节点
        queue<TreeNode*> line;//辅助用的队列
        line.push(root);

        for(int i = 1 ; i < res.size() ; i++)//构造剩下的节点, 串值对应为 null 位置的节点不需要构造
        {
            TreeNode *cur = line.front();
            line.pop();
            //从根节点开始，按层序遍历来说的话，后面紧跟的两个节点就位他的左右孩子节点
            if(res[i] != "null")//不为null的话说明孩子节点存在，构造还在节点并入队列
            {
                cur->left = new TreeNode(atoi(res[i].c_str()));
                line.push(cur->left);
            }

            if(res[++i] != "null")
            {
                cur->right = new TreeNode(atoi(res[i].c_str()));
                line.push(cur->right);
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *p = creatTree();
    preOrder(p);
    cout<<endl;
    string res = Codec().serialize(p);
    cout<<"res : "<<res<<endl;
    cout<<endl;
    TreeNode *q = Codec().deserialize("5,3,6,2,4,null,7,null,null,null,null,null,null,");
    preOrder(q);
    return 0;
}