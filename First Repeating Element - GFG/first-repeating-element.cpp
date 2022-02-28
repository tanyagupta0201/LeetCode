// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) 
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

            if (it -> second > 1) 
            {
                return i + 1; // 1 based indexing
            }
        }

       return -1; // if element is not present
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends