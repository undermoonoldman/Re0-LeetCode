#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i = 0 ; i < s.length() ; i++){
            //遇到左括号就压栈
            if(isLeft(s[i])){
                sta.push(s[i]);
            }
            //遇到右括号，就对当前括号与栈顶括号进行匹配
            else{
                //当前栈为空，遇到了右括号打头的情况
                if(sta.empty()) return false;
                if(isMatch(sta.top(), s[i])){
                    //匹配成功，弹栈
                    sta.pop();
                }
                else
                    return false;
            }
        }
        //匹配串走完且栈为空，是合法的括号
        if(sta.empty())
            return true;
        return false;
    }

private:
    //检查是否是左括号
    bool isLeft(char s){
        if(s == '(' || s =='[' || s =='{')
            return true;
        return false;
    }

    //左右括号匹配判断
    bool isMatch(char a, char b){
        if((a == '(' && b ==')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return true;
        return false;
    }
};
int main() {
    string s = "]";
    bool check = Solution().isValid(s);
    cout<<"check: "<<check<<endl;
    return 0;
}