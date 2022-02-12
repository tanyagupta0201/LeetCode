// https://youtu.be/OyZFFqQtu98 

class Solution {
public:
    void combinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        // Base Case
        if(index == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        // Every element has 2 choices either pick or do not pick
        
        // Pick up element
        if(arr[index] <= target) // we can only pick up an element if its less than or equal to target value
        {
            ds.push_back(arr[index]);
            combinations(index, target - arr[index], arr, ans, ds);
            // After the above recursive call is over we need to remove the last element
            ds.pop_back();
        }
        
        // Do not pick up the element
        combinations(index + 1, target, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        
        combinations(0, target, candidates, ans, ds);
        
        return ans;
    }
};