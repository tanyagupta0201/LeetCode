class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        
        unordered_set<string> s;
        
        for(auto w : words)
        {
            string code = "";
            
            for(auto ch : w)
            {
                code += v[ch - 'a'];
            }
            
            s.insert(code);
        }
        
        return s.size();
    }
};