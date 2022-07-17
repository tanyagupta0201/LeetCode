class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = n - 1; i >= 1; i--)
        {
            int low = 0, high = i - 1;
            
            while(low < high)
            {
                if(nums[low] + nums[high] > nums[i])
                {
                    count += high - low;
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return count;
    }
};

/*
   count += high - low; 
   suppose the sorted array is 10, 21, 22, 100, 101, 200, 300
   
   low = 10, high = 200, arr[i] = 300
   here if (nums[low] + nums[high] > nums[i]) toh agar hum high ko fix rakhein toh low ke aage ki jitni bhi value hain wo sab bhi toh satisfy karengi condition kyuki saare nums usse badhe hain to (high - low) pairs
*/