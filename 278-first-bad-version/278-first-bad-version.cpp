// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long int low = 1, high = n - 1, mid;
        long int res = n; // last number will always be bad
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            
            if(isBadVersion(mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};