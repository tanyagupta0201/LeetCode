class Solution {
public:
    // Answer will be the max digit from the string
    // as to make the maximum digit in the Input String we need that number of 1's
    int minPartitions(string n) 
    {
        int ans = *max_element(n.begin(), n.end()) - '0';  
        
        return ans;
    }
};