class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        int n = s.size();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        int num = freq[s[0] - 'a']; // store the freq of first character of the string

        // freq array can only have 3 types of values
        // 1 -> 0
        // 2 -> value not equal to num
        // 3 -> value equal to num
        for (auto it : freq)
        {
            if (it != 0 && it != num)
            {
                return false;
            }
        }

        return true;
    }
};