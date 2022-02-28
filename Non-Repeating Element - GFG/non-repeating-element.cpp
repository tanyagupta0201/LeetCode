// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends

class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        unordered_map < int, int > mp;

        for (int i = 0; i < n; i++) 
        {
            mp[arr[i]]++;
        }

        for (int i = 0; i < n; i++) 
        {
            int key = arr[i];
            auto it = mp.find(key);

            if (it -> second == 1) 
            {
                return key;
            }
        }

       return 0;
    }
};


// { Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}
  // } Driver Code Ends