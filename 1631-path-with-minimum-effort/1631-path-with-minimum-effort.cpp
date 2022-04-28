class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& nums)
    {
        int n = nums.size() - 1;
        int m = nums[0].size() - 1;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> temp;
        
        temp.push({0,0,0});
        
        while(!temp.empty())
        {            
            // store is  the minimun efforts vector
            vector<int>store = temp.top();
            temp.pop();
            
            int ans = store[0];
            int i = store[1];
            int j = store[2];
            
            // cout<<nums[i][j]<<" -> ";
                
            // return the minimum efforts
            if(i == n && j == m) 
                return ans;
            
            // it prevent to move again to previous position: example [a->b , a<-b]
            if(nums[i][j] == 0) 
                continue;
            
            // move upword
            if(i - 1 >= 0)
            {
                temp.push({max(ans, abs(nums[i - 1][j] - nums[i][j])), i - 1, j});
            }
            
            // move down
            if(i + 1 <= n)
            {
                temp.push({max(ans, abs(nums[i + 1][j] - nums[i][j])), i + 1, j});
            }
            
            // move left
            if(j - 1 >= 0)
            {
                temp.push({max(ans, abs(nums[i][j - 1] - nums[i][j])), i, j-1});
            }
            
            // move right
            if(j + 1 <= m)
            {
                temp.push({max(ans, abs(nums[i][j + 1] - nums[i][j])), i, j+1});
            }
            
            // mark the visited cell
            nums[i][j] = 0;
        }
        
        return 0;
        
    }
};