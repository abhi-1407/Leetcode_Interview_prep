class MinStack {
    multiset<int> s;
    stack<int> st;  
public:
    MinStack() {
                     
    }    
    void push(int val) {
        st.push(val);
        s.insert(val);
    }
    
    void pop() {
        int ele=st.top();
        st.pop();
        s.erase(s.find(ele));
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *s.begin();
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