class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> freq2(26, 0); // frequency vector for words2
        vector<string> ans;

        for (int i = 0; i < words2.size(); i++)
        {

            string current = words2[i]; // current word
            vector<int> temp(26, 0);    // temp freq vector for current word

            for (auto ch : current)
            {
                temp[ch - 'a']++; // update temp

                // update freq2 only if temp[ch-'a'] is greater than freq2[ch-'a']
                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }

        for (int i = 0; i < words1.size(); i++)
        {

            vector<int> freq1(26, 0); // frequency vector for each word of words1
            bool flag = true;

            string current = words1[i]; // current word
            for (auto ch : current)
            { // update freq1
                freq1[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                if (freq2[i] > freq1[i])
                {                 // if for any alphabet, it's count (freq2) is more than the count in freq1,
                    flag = false; // current word is not a subset
                    break;
                }
            }

            if (flag == true)
            {
                ans.push_back(current);
            }
        }

        return ans;
    }
};