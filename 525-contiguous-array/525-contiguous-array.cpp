// https://youtu.be/9ZyLjjk536U

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> m;
        int sum = 0, longest_subarray = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            
            if(sum == 0)
            {
                if(longest_subarray < i + 1)
                    longest_subarray = i + 1;
            }
            else if(m.find(sum) != m.end())
            {
                if(longest_subarray < i - m[sum])
                    longest_subarray = i - m[sum];
            }
            else
            {
                m[sum] = i;
            }
        }
        return longest_subarray;        
    }
};