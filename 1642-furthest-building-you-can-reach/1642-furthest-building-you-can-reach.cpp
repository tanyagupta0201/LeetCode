class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> pq;
        int i = 0, c = 0;
        
        for (i = 0; i < heights.size()-1; ++i)
        {
            c = heights[i+1] - heights[i];
            
            if (c <= 0) 
                continue;
            
            bricks -= c;
            pq.push(c);
            
            if (bricks < 0)
            {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if (ladders < 0) 
                break;
        }
        return i;
        
    }
};