// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int, vector<int> , greater<int>> pq;
        
        for(int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
            
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<int> ans(k);
        
        while(pq.size() > 0)
        {
            ans[k - 1] = pq.top(); // sabse chota element top par hoga abb wo last index par aayega
            pq.pop();
            k--;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends