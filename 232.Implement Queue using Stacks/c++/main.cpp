#include <iostream>
#include <stack>
using namespace std;
/**
 * 232. Implement Queue using Stacks
 *
 * Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

class MyQueue {
private:
    stack<int> inQueue;//入队操作，反序
    stack<int> deQueue;//出队操作，正序
    int size;//队列大小
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }

    /** 入队 o(1)*/
    void push(int x) {
        inQueue.push(x);
        size++;
    }

    /** 出队，o(n)*/
    int pop() {
        /**
         * inQueue 复制到 deQueue
         */
        while(!inQueue.empty()){
            deQueue.push(inQueue.top());
            inQueue.pop();
        }

        /**
         * 在 deQueue 中移除队首
         */
        int ret = deQueue.top();
        deQueue.pop();

        /**
         * deQueue 复制回 inQueue 并清空 deQueue
         */
        while(!deQueue.empty()){
            inQueue.push(deQueue.top());
            deQueue.pop();
        }
        size--;

        return ret;
    }

    /** o(n)*/
    int peek() {
        while(!inQueue.empty()){
            deQueue.push(inQueue.top());
            inQueue.pop();
        }

        int ret = deQueue.top();
        while(!deQueue.empty()){
            inQueue.push(deQueue.top());
            deQueue.pop();
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyQueue myQueue = MyQueue();
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    
    for(int i = 0 ; i < 3 ; i++){
        cout<<myQueue.peek()<<endl;
        myQueue.pop();
    }

    cout<<myQueue.empty()<<endl;

    return 0;
}