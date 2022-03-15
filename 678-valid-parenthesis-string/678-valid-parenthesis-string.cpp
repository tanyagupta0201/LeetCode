/*
    1. Maintain separate stacks for left brackets '(' and stars '*' to store the index values
    2. Answer will be true only if, finally the left bracket stack is empty.
    3. First, try to pop the index from the left bracket stack for each encounter of right bracket.
    4. If there is no index in the bracket stack then try to balance right bracket using the stars stack.
    5. Now, after traversing the string, if left bracket stack is still not empty, then try to empty it using stars stack and
       make sure that only those stars can pop left bracket which have higher index value than bracket.(i.e on the right side of 
       bracket). and...
*/

class Solution {
public:
    
    bool checkValidString(string s) 
    {
        stack<char> open_bracket;
        stack<char> star;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                open_bracket.push(i);
            
            else if(s[i] == '*')
                star.push(i);
            
            // Case of closing bracket
            else 
            {
                if(!open_bracket.empty())
                    open_bracket.pop();
                
                else if(!star.empty())
                    star.pop();
                
                else
                    return false;               
            }
        }
        
        if(!open_bracket.empty())
        {
            while(!open_bracket.empty() && !star.empty() && open_bracket.top() < star.top())
            {
                open_bracket.pop(); 
                star.pop();
            }
        }
        
        return (open_bracket.empty()) ? true : false;        
    }
};