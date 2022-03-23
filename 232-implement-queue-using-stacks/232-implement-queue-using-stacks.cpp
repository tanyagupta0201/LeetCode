class MyQueue {
public:
    stack<int> Input;
    stack<int> Output;
    
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        Input.push(x);
    }
    
    int pop() 
    {
        int tmp;
        if(Output.empty() == false) 
        {
            tmp = Output.top();
            Output.pop();
        }
        else 
        {
            while(Input.empty() == false) 
            {
                Output.push(Input.top());
                Input.pop();
            }
          
            tmp = Output.top();
            Output.pop();
        }
    
        return tmp;
    }
    
    int peek() 
    {
        if(Output.empty() == false) 
        {
            return Output.top();
        }
        else 
        {
            while(Input.empty() == false) 
            {
                Output.push(Input.top());
                Input.pop();
            }
        
            return Output.top();
        }
    }
    
    bool empty() 
    {
        return (Input.empty() && Output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */