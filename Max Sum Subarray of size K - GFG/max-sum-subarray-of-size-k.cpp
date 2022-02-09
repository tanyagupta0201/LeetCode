// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &arr , int n)
    {
        int i = 0, j = 0;
        int sum = 0;
        int maxi = INT_MIN;
        
        while(j < n)
        {
            sum += arr[j];
            
            if(j - i + 1 == K)
            {
                maxi = max(maxi, sum);
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends