class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        for (int i = 0; i < word1.size(); i++)
        {
            f1[word1[i] - 'a']++;
        }

        for (int i = 0; i < word1.size(); i++)
        {
            f2[word2[i] - 'a']++;
        }

        vector<int> cnt(26, 0);

        for (int i = 0; i < 26; i++)
        {
            cnt[i] = abs(f1[i] - f2[i]);
        }

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 3)
                return false;
        }

        return true;
    }
};