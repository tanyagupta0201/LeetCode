// https://youtu.be/G1fRTGRxXU8

class Solution {
public:
    void combinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds)
    {
        // Base Case
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < arr.size(); i++)
        {
            // We won't be making combinations for the same number at the same index
            if(i > index && arr[i] == arr[i - 1]) // i > index means it's not the first time
                continue;
            
            // break the loop if a number is greater than the target
            if(arr[i] > target)
                break;
            
            ds.push_back(arr[i]);
            
            combinations(i + 1, target - arr[i], arr, ans, ds); // i + 1 (not index + 1) as we are picking ith element

            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        // sorting is done as we want final answer in sorted format
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        combinations(0, target, candidates, ans, ds);
        
        return ans;
    }
};