// https://youtu.be/ZVJ3asMoZ18

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> myset;
        
        bool isPresent = false; // checks if endWord is present in wordList or not
        
        // Insert all the wordsfrom WordList to myset
        for(auto word: wordList)
        {
            if(endWord.compare(word) == 0)
                isPresent = true;
            myset.insert(word); // Insert word
        }
        
        if(isPresent == false)  // endWord is not present in the wordList
            return 0;
            
        // BFS - Checking levelwise
        queue<string> q;
        q.push(beginWord);
        
        int depth = 0;
        
        while(!q.empty())
        {
            depth++;
            
            int lsize = q.size(); // number of elements at a level
            
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                
                // checks for all possible words present at a particular level
                for(int i = 0; i < curr.length(); i++) // we will try forming words for each index
                {
                    string temp = curr;
                    
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;
                        
                        if(curr.compare(temp) == 0) 
                            continue;          // skip for the same word
                        
                        if(temp.compare(endWord) == 0)
                            return depth + 1;  // endWord found
                        
                        if(myset.find(temp) != myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    } 
                }
            }
        }
        return 0;
    }
};