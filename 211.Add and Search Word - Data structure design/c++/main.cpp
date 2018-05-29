/**
 * 211. Add and Search Word - Data structure design
 *
 * Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.


 设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

 */

#include <iostream>
#include <unordered_map>
using namespace std;

class WordDictionary {
private:
    class Node{
    public:
        bool isWord;
        unordered_map<char, Node*> next;

        Node(bool isWord){
            this->isWord = isWord;
            next = unordered_map<char, Node*>();
        }

        Node(){
            Node(false);
        }
    };

    Node* root;

    bool match(Node* node, string word, int index){
        if(index == word.length())//递归到底，判断该结点是否为一个单词的结尾
            return node->isWord;
        char c = word[index];

        //不为通配符，匹配下一个位置
        if(c != '.'){
            if(node->next.count(c) == 0)
                return false;
            return match(node->next[c], word, index+1);
        } else{
            //为通配符，尝试匹配每一个分值，只要其中一个分值匹配就返回真，所有分值都不匹配就返回假
            for(unordered_map<char, Node*>::iterator iter = node->next.begin() ; iter != node->next.end() ; iter++)
                if(match(node->next[iter->first], word, index+1))
                    return true;
            return false;
        }
    }


public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(char c : word){
            if(p->next.count(c) == 0)
                p->next.insert(pair<char, Node*>(c, new Node(false)));
            p = p->next[c];
        }
        if(!p->isWord)
            p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(root, word, 0);
    }
};

int main() {
    WordDictionary wordDictionary = WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("mad");
    wordDictionary.addWord("dad");
    cout<<wordDictionary.search("pad")<<endl;
    cout<<wordDictionary.search("bad")<<endl;
    cout<<wordDictionary.search(".ad")<<endl;
    cout<<wordDictionary.search("b..")<<endl;
    return 0;
}