/* Keep two stacks,s1,is just a normal stack and s2 is for keeping the minimum element,while pushing make sure you push only the elements which are smaller than the top of s2,and while popping see if the element which is being popped in s1 is the top element of the s2 */

class MinStack {
    stack<int> s1,s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || val<=getMin())
            s2.push(val);
    }
    
    void pop() {
        if(s1.top()==getMin())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */