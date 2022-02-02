class Solution {
public:
    int binarySearch(vector<int> arr, int l, int r, int x)
    {
        if(r >= l)
        {
            int mid = l + (r - l) / 2;
            
            if(arr[mid] == x)
                return mid;
            
            else if(arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            
            else
                return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target)
    {
        int result = binarySearch(nums, 0, nums.size() - 1, target);
        
        if(result == -1)
            return -1;
        else
            return result;
    }
};