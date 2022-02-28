// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

// https://youtu.be/7xx1YcXXEYU
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) 
	{
	    unordered_map<int, int> mp;
	    
	    for(int i = 0; i < n; i++)
	    {
	        mp[arr[i]]++;
	    }
	    
	    for(auto it : mp)
	    {
	        int key = it.first;
	        int value = it.second;
	        
	        int pair = x - key;
	        
	        if(pair == key)
	        {
	            // Taaki same element repeat na ho
	            if(value > 1)
	            {
	                return true;
	            }
	        }
	        else
	        {
	            if(mp.find(pair) != mp.end())
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends