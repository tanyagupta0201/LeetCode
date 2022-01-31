// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull ugly[n]; // To store ugly numbers
	    
	    ull i2 = 0, i3 = 0, i5 = 0;
	    ull nm2 = 2, nm3 = 3, nm5 = 5;
	    
	    ull nextUgly = 1;
	    
	    ugly[0] = 1; // First ugly number is 1
	    
	    for(int i = 1; i < n; i++)
	    {
	        nextUgly = min(min(nm2, nm3), nm5);
	        
	        ugly[i] = nextUgly;
	        
	        if(nextUgly == nm2)
	        { 
	            i2++;
	            nm2 = ugly[i2] * 2;
	        }
	        
	        if(nextUgly == nm3)
	        { 
	            i3++;
	            nm3 = ugly[i3] * 3;
	        }
	        
	        if(nextUgly == nm5)
	        {
	            i5++;
	            nm5 = ugly[i5] * 5;
	        }
	    }
	    return nextUgly;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends