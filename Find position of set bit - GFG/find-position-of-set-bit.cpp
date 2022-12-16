//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countBits(int n)
    {
        int c = 0;
        while(n > 0)
        {
            n = n & (n - 1);
            c++;
        }
        
        return c;
    }
    
    int findPosition(int n) 
    {
        // code here
        if(countBits(n) != 1)
           return -1;
           
        int pos = 1, i = 1;
        
        while(!(i & n))
        {
            i = i << 1;
            pos++;
        }
        
        return pos;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends