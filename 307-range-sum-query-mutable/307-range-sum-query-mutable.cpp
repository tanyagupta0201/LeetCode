// Without segment tree

class NumArray {
public:
    int sum = 0;
    vector<int> arr; // need to declare it as nums is not global and we need to use this in other functions
    
    NumArray(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i]);
            sum += nums[i];
        }
    }
    
    void update(int index, int val)
    {
        // update the sum
        sum += val - arr[index];
        
        // update the index
        arr[index] = val;
    }
    
    int sumRange(int left, int right)
    {
       int ans = 0;
        /*
        //Two conditions 
        // (i) if - part ==>
        //                 range(left, right) is less than half of array length, then calculating sum from left to right
        // (ii) else part ==>
        //                 range(left, right) is greater than half of array length, then calculating sumRange by subtracting sum from 0th // index to left-1 and from right+1 to last index from the global sum.
        */
        
        
        if(right - left < arr.size() / 2)
        {
            ans = accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
        }
        else
        {
            ans = sum - accumulate(arr.begin(), arr.begin() + left, 0) - accumulate(arr.begin() + right + 1, arr.end(), 0);
        }
        
        
        // accumulate ==> sum of elements in between the given positons and inclusive
        return ans; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */