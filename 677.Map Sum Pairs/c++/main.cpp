/**
 * 677. Map Sum Pairs
 * Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5


 实现一个 MapSum 类里的两个方法，insert 和 sum。

对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。

对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:

输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5

 */
#include <iostream>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    class Node{
    public:
        int val;//非单词结点的权重为零，单词结点的权重不为零
        unordered_map<char, Node*> next;

        Node(int val){
            this->val = val;
            next = unordered_map<char, Node*>();
        }

        Node(){
            Node(0);
        }
    };

    Node* root;

    //递归计算某结点的子树所有单词结点权重的加和
    int doSum(Node* node){
        int total = 0;
        //结点为单词结点，记录权重
        if(node->val != 0)
            total += node->val;
        //递归到底的情况，叶子结点无法跳转，直接返回
        if(node->next.size() == 0)
            return total;
        else{
            //非叶子结点，计算每一条分支的权重和，累加得到整颗树的权重和
            for(unordered_map<char, Node*>:: iterator ite = node->next.begin() ; ite != node->next.end() ; ite++)
                total += doSum(node->next[ite->first]);
            return total;
        }

    }

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }

    void insert(string key, int val) {
        Node* p = root;
        for(char c : key){
            if(p->next.count(c) == 0)
                p->next.insert(pair<char, Node*>(c, new Node(0)));
            p = p->next[c];
        }
        p->val = val;
    }

    //计算符合某前缀的所有单词权重的加和
    int sum(string prefix) {
        //先查询字典树中是否有该前缀，不存在该前缀，直接返回零
        Node* p = root;
        for(char c : prefix){
            if(p->next.count(c) == 0)
                return 0;
            p = p->next[c];
        }
        //存在该前缀，计算单词权重加和
        return doSum(p);
    }
};

int main() {
    MapSum mapSum = MapSum();
    mapSum.insert("apple", 3);
    cout<<mapSum.sum("ap")<<endl;
    mapSum.insert("app", 2);
    cout<<mapSum.sum("ap")<<endl;
    return 0;
}