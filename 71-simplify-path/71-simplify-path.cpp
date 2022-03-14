// https://youtu.be/DJc7mkMH_eM

class Solution {
public:
    string simplifyPath(string path) 
    {
        int idx = path.size() - 1; // Zero based indexing
        string ans = "";
        int back = 0;
        
        while(idx >= 0)
        {
            string temp = "";
            
            while(idx >= 0 && path[idx] != '/')
            {
                temp = path[idx] + temp; // temp stores the content between 2 slashes
                idx--;    
            }
            
            idx--; // So that it does not start with /
            
            if(temp == "" || temp == ".")
                continue;
            
            if(temp == "..")
            {
                back++;
            }
            else if(back > 0)
            {
                back--;
            }
            else
            {
                ans = temp + ans;
                ans = "/" + ans;
            }
        }
        
        if(ans == "")
            return "/";
        
        return ans;
    }
};