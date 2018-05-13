/*20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

/*栈的经典应用，有左括号一直压栈，遇到右括号，如果当前栈不为空，匹配栈顶与当前字符，匹配成功，弹栈，匹配下个字符，匹配失败，返回false
 * 当串匹配到结尾时栈也全部弹空，返回true. 否则返回false*/
#include <stdio.h>
#include <stdbool.h>
#define maxContain 3999
typedef struct stack
{
    char contain[4000];

    int top;
}stack;

stack Stack;

void push(char value)
{
    if(Stack.top == maxContain)
        return;
    Stack.top += 1;
    Stack.contain[(Stack.top)] = value;
}

void pop()
{
    if(Stack.top >= 0)
        Stack.top -= 1;
}

bool isLeftParent(char *p)
{
    if(*p == '(' || *p == '[' || *p == '{')
        return true;
    else
        return false;
}

bool isRightParent(char *p)
{
    if(*p == ')' || *p == ']' || *p == '}')
        return true;
    else
        return false;
}

bool isMatch(char c)
{
    if(Stack.contain[Stack.top] == '(' && c == ')')
        return true;
    else if(Stack.contain[Stack.top] == '[' && c == ']')
        return true;
    else if(Stack.contain[Stack.top] == '{' && c == '}')
        return true;
    else
        return false;

}

bool isValid(char* s)
{
    if(*s == '\0')
        return false;
    char *p = s;
    Stack.top = -1;
    if(isRightParent(p))
        return false;
    while(*p)
    {
        if(isLeftParent(p))
        {
            push(*p);
            p++;
        }

        if(isRightParent(p))
        {
            if(Stack.top == -1)//很必要的检查
                return false;
            if(isMatch(*p))
            {
                pop();
                p++;
            }
            else
                return false;
        }
    }
    if(Stack.top == -1)
        return true;
    else
        return false;
}

int main() {
    printf("Hello, World!\n");
    char *s = "[])";
    int check = isValid(s);
    printf("check = %d\n",check);
    return 0;
}