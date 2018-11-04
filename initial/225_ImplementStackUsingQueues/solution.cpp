#include "../IOLib.hpp"

/* Use two queues.
 * Time: push: O(1), pop: O(n)
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        container.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = top();
        container.pop();
        while(!temp.empty()){
            container.push(temp.front());
            temp.pop();
        }
        return result;
    }
    
    /** Get the top element. */
    int top() {
        while(container.size() > 1){
            temp.push(container.front());
            container.pop();
        }
        return container.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return container.empty() && temp.empty();
    }
private:
    queue<int> container, temp;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
