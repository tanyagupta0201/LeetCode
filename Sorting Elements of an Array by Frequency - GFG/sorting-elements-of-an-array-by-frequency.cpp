#include <bits/stdc++.h>
using namespace std;

class myComp{
public:
      int operator()(pair<int, int> &p1, pair<int, int> &p2)
      {
          if(p1.first < p2.first)
          {
              return true;
          }
          else if(p1.first > p2.first)
          {
              return false;
          }
          else
          {
              if(p1.second > p2.second)
                  return true;
                  
              return false;
          }
      }
};

int main() 
{
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    unordered_map<int, int> mp;
	    
	    for(int i = 0; i < n; i++)
	        mp[arr[i]]++;
	        
	    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
	    
	    for(auto it = mp.begin(); it != mp.end(); it++)
	    {
	        pq.push({it->second, it->first});
	    }
	    
	    while(!pq.empty())
	    {
	        int freq = pq.top().first;
	        int val = pq.top().second;
	        
	        while(freq > 0)
	        {
	            cout << val << " ";
	            freq--;
	        }
	        
	        pq.pop();
	    }
	    
	    cout << endl;
	}
	
	return 0;
}