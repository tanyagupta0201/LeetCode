// https://youtu.be/qEIGhVtZ-sg

class Solution {
public:
    static bool comp(string first, string second)
    {
        string one = first + second;
        string two = second + first;
        
        int i = 0;
        // Ek ek karke character compare karna hai
        while(one[i] && two[i])
        {
            if(one[i] > two[i])
                return true;
            else if(one[i] < two[i])
                return false;
            i++;
        }
        return false;
    }
    
    string largestNumber(vector<int>& nums)
    {
        vector<string> str;
        bool allZeros = true; // edge case - if all numbers are zero then answer will be 0 if we skip this the answer will be like 000
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
                allZeros = false;
            
            str.push_back(to_string(nums[i]));
        }
        
        // If all the numbers are zero then simply return zero
        if(allZeros)
        {
            return to_string(0);
        }
        
        sort(str.begin(), str.end(), comp);
        
        string result;
        
        for (int i = 0; i < str.size(); i++)
            result += str[i];
                        
        return result;
    }
};