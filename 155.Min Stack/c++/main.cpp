#include <iostream>
#include <stack>
using namespace std;

/**
 *155. Min Stack
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */

class MinStack {
private:
    stack<int> valueOrder;//排序栈，插入元素从大到小，栈顶最小
    stack<int> insertOrder;//顺序栈，维持原始的插入顺序
public:

    MinStack() {

    }

    /**
     * 排序栈只插入不大于当前栈顶的元素
     */
    void push(int x) {
        insertOrder.push(x);
        if(valueOrder.empty())
            valueOrder.push(x);
        else
            if(x <= valueOrder.top())
                valueOrder.push(x);
    }

    /**
     * 弹出时排序栈只弹出与顺序栈中相同的元素
     */
    void pop() {
        int temp = insertOrder.top();
        insertOrder.pop();

        if(valueOrder.top() == temp)
            valueOrder.pop();
    }

    int top() {
        return insertOrder.top();
    }

    int getMin() {
        return valueOrder.top();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}