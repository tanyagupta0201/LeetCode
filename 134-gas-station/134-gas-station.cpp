class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        
        int What_We_have = 0;
        int What_We_Require = 0;
        
        for(int i = 0; i < n; i++)
        {
            What_We_have += gas[i]; 
        }
        
        for(int i = 0; i < n; i++)
        {
            What_We_Require += cost[i]; 
        }
        
        if(What_We_have < What_We_Require)
            return -1;
        
        int curr = 0, start = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr += (gas[i] - cost[i]);
            
            if(curr < 0)
            {
                start = i + 1;
                curr = 0;
            }
        }
        
        return start;        
    }
};