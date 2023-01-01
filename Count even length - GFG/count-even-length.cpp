//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1000000007;
	
	long long inv(long long int r)
	{
	    if(r == 1)
	      return 1;
	      
	    return (mod - ((mod / r) * inv(mod % r)) % mod + mod) % mod;
	}
	
	int compute_value(int n)
	{
	    long long int ans = 1, ncr = 1;
	    
	    for(int r = 1; r <= n; r++)
	    {
	        ncr = (((ncr * (n + 1 - r)) % mod) * inv(r)) % mod;
	        ans += ((ncr * ncr) % mod) % mod;
	    }
	    
	    return ans % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends