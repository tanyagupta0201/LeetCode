class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int cnt = 0;
        int idx = 0;
        int maxReach = startFuel;
        priority_queue<int> pq;
        
        while(maxReach < target)
        {
            // Storing the fuel provided by gas ststion in priority queue
            while(idx < stations.size() and stations[idx][0] <= maxReach)
            {
                pq.push(stations[idx][1]);
                idx++;
            }
            
            // not possible
            if(pq.empty())
                return -1;
            
            maxReach += pq.top();
            pq.pop();
            
            cnt++;
        }
  
        return cnt;
    }
};