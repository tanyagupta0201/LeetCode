class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        // if the size is not divisible then we cannot divide the array
        if (n % groupSize != 0)
            return false;

        // sort the array
        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;
        for (auto it : hand)
            mp[it]++;

        for (int i = 0; i < n; i++)
        {
            // if the curr element does not exists in the map, then skip the rest part
            if (mp[hand[i]] == 0)
                continue;

            // if present so I need to check for its consecutive elements
            // so decrease its one occurence from the map
            mp[hand[i]]--;

            // Now check for its consecutive elements
            for (int j = 1; j < groupSize; j++)
            {
                // check if next consecutive element is present or not, if not simply return false
                if (mp[hand[i] + j] == 0)
                {
                    return false;
                }

                // if present, decrease its occurence from the map
                mp[hand[i] + j]--;
            }
        }

        return true;
    }
};