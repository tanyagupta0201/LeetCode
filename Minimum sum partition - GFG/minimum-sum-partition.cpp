// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  
	{ 
	    // Your code goes here
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        bool dp[n + 1][sum + 1];
        
        for(int i = 0; i < sum + 1; i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < sum + 1; j++)
            {
                if(nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]; 
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        vector<int> v;
        for(int i = 0; i < (sum / 2) + 1; i++)
        {
            if(dp[n][i] == 1)
            {
                v.push_back(i);
            }
        }
        
        int mini = INT_MAX;
        
        for(int i = 0; i < v.size(); i++)
        {
            mini = min(mini, sum - 2 * v[i]);
        }
        
        return mini;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends