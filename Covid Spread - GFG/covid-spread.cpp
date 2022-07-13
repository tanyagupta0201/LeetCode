// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        if(hospital.empty())
           return 0;
           
         int r = hospital.size();
         int c = hospital[0].size();
         int nonZero = 0;
         queue<pair<int, int>> q; // {x, y} dimensions
         
         for(int i = 0; i < r; i++)
         {
             for(int j = 0; j < c; j++)
             {
                 if(hospital[i][j] == 2)
                 {
                     q.push({i, j});
                 }
                 
                 if(hospital[i][j] != 0)
                 {
                     nonZero++;
                 }
             }
         }
         
         // 4 possible directions
         int dx[4] = {0, 0, 1, -1};
         int dy[4] = {1, -1, 0, 0};
         
         int time = 0, cnt = 0;
         
         while(!q.empty())
         {
             int sz = q.size();
             cnt += q.size();
             
             while(sz--)
             {
                 auto it = q.front();
                 q.pop();
                 
                 int i = it.first;
                 int j = it.second;
                 
                 for(int k = 0; k < 4; k++)
                 {
                     int xCordinate = i + dx[k];
                     int yCordinate = j + dy[k];
                     
                     // these are all invalid conditions
                     if(xCordinate < 0 || xCordinate >= r || yCordinate < 0 || yCordinate >= c || hospital[xCordinate][yCordinate] != 1)
                     {
                         continue;
                     }
                     
                     hospital[xCordinate][yCordinate] = 2;
                     q.push({xCordinate, yCordinate});
                 }
             }
             
             if(!q.empty())
             {
                 time += 1;
             }
         }
         
         if(cnt == nonZero)
         {
             return time;
         }
         else
         {
             return -1;
         }
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends