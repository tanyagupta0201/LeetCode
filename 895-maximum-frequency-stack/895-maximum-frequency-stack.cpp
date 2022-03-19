/*
    1. We will take a variable max_frequency which indicate the maximum number of ocurrence.
    
    2. We will consider a frequency map that will count the occurences of each element.
    
    3. We will also consider a map group_stack which will group the elements with the same frequecy. 
       Example if two elements have same count then we will add them in stack with the recent element at the top.
    
    4. When we will push the elements
       a) We will increment its frequency
       b) Update the maximum occurence element
       c) group the element with its frequency
    
    5. When we will pop the element from stack
       a) We will take out the max_frequency element.
       b) Remove it from group_stack
       c) Decrement its freuency
       d) Return it
       
       https://youtu.be/0fRmVjxopiE
       https://leetcode.com/problems/maximum-frequency-stack/discuss/1861911/C%2B%2B-or-Easy-solution-with-explanation-or-Simple-solution
*/

class FreqStack {
public:

    // This will store the count of each element
    unordered_map<int, int> frequency;
    
    // This maps the elements which have same count
    // But the element that come last will come first of same count
    unordered_map<int, stack<int>> group_stack;
    
    // Maximum frequency possible
    int max_frequency=0;
    
    FreqStack() 
    {
              
    }
    
    void push(int val) 
    {
        // Increment the count
        frequency[val]++;
        
        // Check is this element occurs maximum time
        max_frequency = max(max_frequency, frequency[val]);
        
        // Map the element with its count
        group_stack[frequency[val]].push(val);
    }
    
    int pop() 
    {
        // Find the max occurence element
        int top_max_frequency = group_stack[max_frequency].top();
        
        // Remove it from stack
        group_stack[max_frequency].pop();
        
        // Decrement its count
        frequency[top_max_frequency]--;
        
        // If there is no element of maximum frquency the decrement max_frequency
        if(group_stack[max_frequency].size() == 0)
            max_frequency--;
        
        return top_max_frequency;   
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */