class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int i = 0, j = 0;
        int ans = 0;
        int n = chars.size();
        
        while(i < n)
        {
            j = i + 1;
            
            while(j < n && chars[i] == chars[j])
            {
                j++;
            }
            
            chars[ans++] = chars[i];
            
            int len = j - i;
            
            if(len > 1)
            {
                string count = to_string(len);
                
                for(char ch : count)
                {
                    chars[ans++] = ch;
                }
            }
            
            i = j;
        }
        
        return ans;
    }
};