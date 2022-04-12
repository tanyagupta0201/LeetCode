// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int, int>> st; // {Next greatest element. index}
       
       vector<int> v(n);
    

       for (int i = 0; i < n; i++)
       {
           if (st.size() > 0)
           {
               while (st.size() > 0 && st.top().first <= price[i])
               {
                  st.pop();
               }
           }

           if (!st.empty())
               v[i] = st.top().second;
           else
               v[i] = -1;

           st.push({price[i], i});
        }

        for(int i = 0; i < v.size(); i++)
        {
            v[i] = i - v[i]; // curr index - next greatest element index
        }
       
       return v;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends