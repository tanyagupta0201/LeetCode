// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    /*
        Intuition
        Since we want to minimise the sum of two numbers to be formed, 
        we must divide all digits in two halves and assign half-half digits to them. 
        We also need to make sure that the leading digits are smaller.
        
        So we need to keep the leading digits as small as possible. 
        So after sorting the given array. We will initialise two variables a and b with the value of 0.
        Now we will traverse the whole array and alternatively we will add the numbers to a and b respectively by multiplying with 10 as each time we add the number of digits will increase. 
        So after traversing the whole array we will be able to calculate the minimum answer.
    */
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr, arr + n);
        long long int even = 0, odd = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                even = even * 10 + arr[i];
            }
            else
            {
                odd = odd * 10 + arr[i];
            }
        }
        
        return even + odd;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends