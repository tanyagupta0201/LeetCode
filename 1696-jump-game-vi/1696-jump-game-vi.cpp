class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int> res(nums.size());
        deque<int> dq;
        
        dq.push_back(0);
        res[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) 
        {
			// dq.front() will give the index of maximum element in array res, then adding it to the current element
            res[i] = res[dq.front()] + nums[i];
			
			// removing elements with less value than the current value from back, since they will be of no use
            while (dq.size() && res[dq.back()] < res[i]) dq.pop_back();
			
			// then adding the current index
            dq.push_back(i);
			
			// removing index if size becomes greater than window size k
            if (dq.front() <= i - k) dq.pop_front();
        }
        
		// returning last element of res array which is our ans
        return res.back();
    }
};