class MinStack {
public:
    // Method 1 - O(n) complexity
    // Using extra stack
    stack<int> s, ss;
    
    MinStack() {
        
    }
    
    void push(int val) 
    {
        s.push(val);
        
        if(ss.size() == 0 || val <= ss.top())
            ss.push(val);        
    }
    
    void pop() 
    {
        int ans;
        
        if(s.size() > 0)
        {
            ans = s.top();
            s.pop();
        }
        
        if(ans == ss.top() && ss.size() > 0)
            ss.pop();
    }
    
    int top()
    {
        if(s.size() == 0)
            return -1;
        
        return s.top();
    }
    
    int getMin() 
    {
        if(ss.size() == 0)
            return -1;
        
        return ss.top();        
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