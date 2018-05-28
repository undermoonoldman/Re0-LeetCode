/**
 * 208. Implement Trie (Prefix Tree)
 * Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

注意:
你可以假设所有的输入都是由小写字母 a-z 构成的。

 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Trie {
private:
    class Node{
    public:
        unordered_map<char, Node*> next;
        bool isWord;

        Node(bool isWord){
            this->isWord = isWord;
            next = unordered_map<char, Node*>();
        }
    };

    Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(false);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(char c : word){
            if(p->next.count(c) == 0)
                p->next.insert(pair<char, Node*>(c, new Node(false)));
            p = p->next[c];
        }
        if(!p->isWord)
            p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(char c : word){
            if(p->next.count(c) == 0)
                return false;
            p = p->next[c];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for(char c : prefix){
            if(p->next.count(c) == 0)
                return false;
            p = p->next[c];
        }
        return true;
    }
};

int main() {
    Trie trie = Trie();
    trie.insert("abc");
    cout<< trie.search("abc")<<endl;
    cout<< trie.startsWith("ab")<<endl;
    return 0;
}