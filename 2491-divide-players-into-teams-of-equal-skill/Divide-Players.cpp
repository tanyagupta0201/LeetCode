class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        long long chemistry = 0;
        // sort the array
        sort(skill.begin(), skill.end());

        for (int i = 0; i < n / 2; i++)
        {
            // Total skill of each group should be equal else return not possible
            // so return -1
            if ((skill[i] + skill[n - i - 1]) != (skill[0] + skill[n - 1]))
                return -1;

            chemistry += (skill[i] * skill[n - i - 1]);
        }

        return chemistry;
    }
};