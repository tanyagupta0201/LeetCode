class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        priority_queue<double> pq;
        
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        double k = 0;
        int steps = 0;
        
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        
        while(sum - k > sum / 2)
        {
            double ele = pq.top();
            pq.pop();
            
            k += ele / 2;
            pq.push(ele / 2);
            steps++;
        }
        
        return steps;        
    }
};