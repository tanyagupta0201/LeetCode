// https://www.youtube.com/watch?v=XgP3w7Txvlc

class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        vector<bool> vis(n, false);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int i = q.front();
                q.pop();
                
                // check if the curr index is at last position
                if(i == n - 1)
                {
                    return steps;
                }
                
                // put all the possible values in the next vector from the current index
                vector<int> &next = mp[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                
                // now check for the valid next index in the next vector
                for(int j : next)
                {
                    if(j >= 0 && j < n && !vis[j])
                    {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            
            steps++;
        }
        
        // if it is impossible to reach the last index
        return 0; 
    }
};