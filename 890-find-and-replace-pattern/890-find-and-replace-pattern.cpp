/*
// Using 2 maps

class Solution {
public:
    bool check(string w1, string w2)
    {
        // mp1 -> word1 -> word2
        // mp2 -> word2 -> word1
        unordered_map<char, char> mp1, mp2;
        
        for(int i = 0; i < w1.size(); i++)
        {
            if( (mp1.count(w1[i]) && mp1[w1[i]] != w2[i]) || (mp2.count(w2[i]) && mp2[w2[i]] != w1[i]) )
            {
                return false;
            }
            else
            {
                mp1[w1[i]] = w2[i];
                mp2[w2[i]] = w1[i];
            }   
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        
        for(auto &word: words)
        {
            if(check(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }
};

*/

// Using 1 map
class Solution {
public:
    
    bool check(string &w1, string &w2)
    {
        // Maps character of w1 to character of w2
        unordered_map<char, char> mp;
        
        // Mapping w1[i] -> w2[i] and also checking w1[i] -> w2[i] is unique
        for(int i = 0; i < w1.size(); i++)
        {
            // If there is a map for current character, and it is not matching, then we return false.
            // Otherwise we simply map the character
            if(mp.count(w1[i]) && mp[w1[i]] != w2[i])
                return false;
            else
                mp[w1[i]] = w2[i];
        }
        
        // Checking w2[i] -> w1[i] is unique
        // Once all the letters are mapped, we re-iterate over the mappings and ensure that each w2[i] is only mapped to single w1[i].
        bitset<26> visited;
        for(auto p: mp)
        {    
            // If already visited the current character, then return false
            // Otherwise mark it as visited.
            if(visited[p.second - 'a'])
                return false;
            else
                visited[p.second - 'a'] = true;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string> ans;
        
        for(auto &word: words)
        {
            if(check(word, pattern))
                ans.push_back(word);
        }
        
        return ans;        
    }
};