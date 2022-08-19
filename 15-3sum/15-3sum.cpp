class Solution {
public:
    // TC = O(N ^ 2), SC = O(M)
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i <= n - 3; i++) // keeping i fix and iterate only till 3rd last element 
        {
            // take i only if it is a first element and avoid all duplicates
            if(i == 0 || i > 0 && nums[i] != nums[i - 1])
            {
               int low = i + 1, high = n - 1;
               // i + j + k = 0
               // j + k = -i
               int sum = -(nums[i]);
            
               while(low < high)
               {
                  if(nums[low] + nums[high] == sum)
                  {
                      vector<int> t;
                      t.push_back(nums[i]);
                      t.push_back(nums[low]);
                      t.push_back(nums[high]);
                      ans.push_back(t);
                      // Avoid duplicates
                      while(low < high && nums[low] == nums[low + 1])
                          low++;
                      
                      while(low < high && nums[high] == nums[high - 1])
                          high--;
                      
                      low++;
                      high--;
                  }
                  else if(nums[low] + nums[high] < sum)
                  {
                      low++;
                  }
                  else
                  {
                      high--;
                  }
               }
           }
        }
        return ans;
    }
};