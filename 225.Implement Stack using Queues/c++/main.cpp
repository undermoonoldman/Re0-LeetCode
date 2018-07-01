#include <iostream>
#include <queue>
using namespace std;
/**
 * 225. Implement Stack using Queues
 *
 * Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

class MyStack {
private:
    queue<int> inStack;
    int size;
public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
    }

    /** 入栈 o(1)*/
    void push(int x) {
        inStack.push(x);
        size++;
    }

    /** 出栈 o(n)*/
    int pop() {
        int ret = inStack.back();//队尾，也是栈顶

        //队首出队插入队尾，直到原来队尾变为队首
        for(int i = 0 ; i < size-1 ; i++){
            inStack.push(inStack.front());
            inStack.pop();
        }

        //队首移除，弹栈
        inStack.pop();
        size--;

        return ret;
    }

    /** o(1) */
    int top() {
        return inStack.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}