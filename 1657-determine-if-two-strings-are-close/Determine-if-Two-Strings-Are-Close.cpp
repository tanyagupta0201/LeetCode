class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> s1(26, 0), s2(26, 0), s3(26, 0), s4(26, 0);

        for (auto x : word1)
        {
            s1[x - 'a']++;
            s3[x - 'a'] = 1; // mark that this char exists
        }

        for (auto x : word2)
        {
            s2[x - 'a']++;
            s4[x - 'a'] = 1; // mark that this char exists
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2 && s3 == s4;
    }
};