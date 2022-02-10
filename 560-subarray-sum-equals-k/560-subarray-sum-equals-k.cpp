// https://youtu.be/HbbYPQc-Oo4

// Brute Force: find all the subarrays and count the total number of subarrays whose sum is equal to k - O(n ^ 3)


/*

If anyone is confused why the count was increased by myMap[ curr - k ] instead of just count+=1 . It was because prefix sum can be same because of some negative values in the array. so out next occuring k will also pair  with those negative values also . 


consider this case A : [3 4  7    2   -3   1   4   2   1 ]  
                       preSum : [3 7 14 16 13 14 18 20 21]


you can see 14 occured twice  because of the subsequence [2 -3 1] their sum is 0. so When you are at the final index with value 1 . you have curr - k = 21 - 7 = 14 . you check for 14 it has occured twice . so you need to consider subsequences [2 -3 1 4 2 1] and [4 2 1] . Hope this helps

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        unordered_map<int, int> m;
        
        int i = 0, currSum = 0;
        
        int count = 0; // to store number of subarrays
        
        while(i < n)
        {
            currSum += nums[i];
            
            if(currSum == k)
                count += 1;
            
            if(m.find(currSum - k) != m.end())
                count += m[currSum - k];
            
            m[currSum] += 1;
            i++;            
        }
        
        return count;
    }
};