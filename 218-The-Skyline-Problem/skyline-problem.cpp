/*
We use multiset for certain resons,
first being, to store similar values multiple times as a few buildings may have same height
second being, it is difficult to search for a certain height in the pq, while we can search any element using the find()
and can delete it using the erase() and for the top value,
i.e, the concept used for the pq, the multiset stores the min value at top, so to get the max value(last element of the set),
we can use rbegin() which returns a pointer to the last element
and then we can further use the * operator to get the value at the pointer/largest element/last element of the set

*/

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        vector<pair<int, int>> t;

        // in order to distinguish the coordinates
        // x coordinate with -ve height
        // y coordinate with +ve height
        for (auto it : buildings)
        {
            t.push_back({it[0], -it[2]});
            t.push_back({it[1], it[2]});
        }

        // since we want our answer in increasing order therefore we need to sort the coordinates
        sort(t.begin(), t.end());

        // to store in descending order
        // as we always want max height
        multiset<int, greater<int>> s;

        s.insert(0); // initially 0 height
        int height = 0;

        // Now we want only those coordinates that would contribute to answer
        // coordinates due to which there would be change in height
        for (auto it : t)
        {
            int currH = it.second;
            int currX = it.first;

            if (currH < 0)
            {
                // starting point of rectangle
                s.insert(-currH);
            }
            else
            {
                // end point of rectangle
                // we need to remove it from set as this rectanle is ending
                s.erase(s.find(currH));
            }

            int top = *s.begin(); // this would give max height

            // if there is change in height
            if (top != height)
            {
                height = top; // update the curr height
                ans.push_back({currX, top});
            }
        }

        return ans;
    }
};