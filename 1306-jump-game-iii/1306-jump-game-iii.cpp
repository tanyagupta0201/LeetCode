class Solution {
public:
    bool helper(int idx, int n, vector<int> &arr, vector<bool> &dp)
    {
        if(idx >= n || idx < 0)
            return false;
     
        if(arr[idx] == 0)
            return true;
 
        if(dp[idx] == true) // we have already visited it
            return false;
        
        dp[idx] = true;
        
        int way1 = helper(idx + arr[idx], n, arr, dp);
        int way2 = helper(idx - arr[idx], n, arr, dp);
        
        return dp[idx] = way1 || way2;
    }
    
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        vector<bool> dp(n, false);
        
        return helper(start, n, arr, dp);        
    }
};