/*

// Used Vector of pair -> vector<pair<int,int>> and priority queue(min heap)
// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3

// sort with respect to efficiency: <efficiency, speed>
// <9, 1>, <7, 5>, <5, 2>, <4, 10>, <3, 3>, <2, 8>

// consider efficiency as 9:
// ans = max(ans, sum * min_efficiency) = 1 * 9 = 9

// consider next engineer with efficiency 7:
// ans = max(ans, sum * min_efficiency) = (1 + 5) * 7 = 42

// consider next engineer with efficiency 5:
// ans = max(ans, sum * min_efficiency) = (1 + 5 + 2) * 5 = 40

// consider next engineer with efficiency 4:
// ans = max(ans, sum * min_efficiency) = (1 + 5 + 2 + 10) * 4

// size of team greater than k so remove engineer with lowest speed because anyhow efficiency will be 4
// ans = max(ans, sum * min_efficiency) = (5 + 2 + 10) * 4 = 68

// likewise, stop when size is greater than k

// We can use min heap to remove engineer with lowest speed

// Complexity

// Time Complexity: O(NlogN + NlogK), NlogN for sorting n engineers by decreasing of their efficiency, NlogK to iterate all engineers, each time need to perform logK for heappush/heappop.
// Space Complexity: O(N + K)

*/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        // vector of pair of integers
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++)
        {
            engineers.push_back({efficiency[i], speed[i]});
        }
        // sort by efficiency and then by speed, descending
        sort(engineers.rbegin(), engineers.rend());

        // takung min heap, so used greater<int>
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int sum = 0, ans = 0;

        // itereate through efficiency
        for (int i = 0; i < n; i++)
        {
            sum += engineers[i].second;
            // for each efficiency, find the maximum possible combination(of size <= k) of speed
            // possible speeds are the speed whose efficiency >= current efficiency
            pq.push(engineers[i].second);

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            ans = max(ans, sum * engineers[i].first);
        }
        
        // why use % 1000000007? because in ques, it's written, *Since the answer can be a huge number, return it modulo 109 + 7.*
        return ans % 1000000007;
        
    }
};