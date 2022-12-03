// https://youtu.be/UvpXInRkZ3Q

class Solution
{
public:
    // hum group ke size ke liye GCD of all the freq nikalenge
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> mp;
        for (auto it : deck)
        {
            mp[it]++;
        }

        int ans = 0;
        for (auto it : mp)
        {
            ans = __gcd(ans, it.second);
        }

        if (ans > 1)
            return true;
        return false;
    }
};