// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
  public:
  // https://youtu.be/hCGUty76A6M -> 2nd Method
    vector<int> PosNegPair(int a[], int n) 
    {
         vector<int> res;
         map<int, int> mp;
         
         for(int i = 0; i < n; i++)
         {
             mp[a[i]]++;
         }
         
        for(auto i : mp)
        {
            int num = i.first;
            if(num > 0)
            {
                while(mp[num] > 0 && mp[-1 * num] > 0)
                {
                    res.push_back(-1 * num);
                    res.push_back(num);
                    mp[num]--;
                    mp[-1 * num]--;
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends