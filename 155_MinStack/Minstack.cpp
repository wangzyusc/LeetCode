#include "../IOLib.hpp"

using namespace std;

class MinStack {
private:
    stack<int> nums;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        if(mins.empty() || x <= mins.top()) mins.push(x);
    }
    
    void pop() {
        if(nums.top() == mins.top()){
            mins.pop();
        }
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(void){
  MinStack obj;
  obj.push(-2);
  obj.push(0);
  obj.push(-3);
  cout << "Min is " << obj.getMin() << " (should be -3)" << endl;
  obj.pop();
  cout << "Top is " << obj.top() << " (should be 0)" << endl;
  cout << "Min is " << obj.getMin() << " (should be -2)" << endl;
  return 0;
}
