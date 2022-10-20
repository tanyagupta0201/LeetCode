class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int freq[26] = {0};

        for (auto ch : sentence)
        {
            freq[ch - 'a']++;
        }

        for (auto it : freq)
        {
            if (it == 0)
                return false;
        }

        return true;
    }
};