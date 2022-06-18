class WordFilter
{
    unordered_map<string, unordered_map<string, int>> m;
    unordered_map<string, int> ms;

public:
    WordFilter(vector<string> &words)
    {

        for (int i = words.size() - 1; i >= 0; i--)
        {

            if (ms.count(words[i]) == 0)
            {

                ms[words[i]]++;
                string prefix = "";
                
                for (int j = 0; j < words[i].size(); j++)
                {
                    prefix += words[i][j];
                    string suffix = "";
                    
                    for (int k = words[i].size() - 1; k >= 0; k--)
                    {
                        suffix = words[i][k] + suffix;
                        
                        if (m.count(prefix) == 0)
                            m[prefix][suffix] = i;
                        else if (m[prefix].count(suffix) == 0)
                        {
                            m[prefix][suffix] = i;
                        }
                    }
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        return m.count(prefix) ? m[prefix].count(suffix) > 0 ? m[prefix][suffix] : -1 : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */