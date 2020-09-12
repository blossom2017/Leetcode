class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int x) {
        st1.push(x);
        if(st2.empty()||x<=getMin())st2.push(x);
    }
    
    void pop() {
        int q = st1.top();
        st1.pop();
        if(q==getMin())st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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
