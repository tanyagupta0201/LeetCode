// https://youtu.be/gl57zvHrgrQ

// TC = O(N ^ 4)
// SC = O(N ^ 2)

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();

        vector<pair<int, int>> v1; // stores the positions of 1 for img1
        vector<pair<int, int>> v2; // stores the positions of 1 for img1

        // stores the position of 1 in the respective vectors
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1)
                {
                    v1.push_back({i, j});
                }

                if (img2[i][j] == 1)
                {
                    v2.push_back({i, j});
                }
            }
        }

        int ans = 0;
        /*
          If we wish to hash a pair in an unordered map, we must explicitly supply it with a hash function that can hash a
          pair because an unordered map does not have a hash function for a pair as it does for an int, string, etc.
        */
        map<pair<int, int>, int> mp;

        for (auto [i1, j1] : v1)
        {
            for (auto [i2, j2] : v2)
            {
                mp[{i2 - i1, j2 - j1}]++;

                ans = max(ans, mp[{i2 - i1, j2 - j1}]);
            }
        }

        return ans;
    }
};