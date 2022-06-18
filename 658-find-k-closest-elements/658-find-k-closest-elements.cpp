class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans(k);
        priority_queue<pair<int, int>> pq; // max heap of pairs
        
        for(int i = 0; i < arr.size(); i++)
        {
            int key = abs(arr[i] - x);
            int value = arr[i];
            
            pq.push({key, value});
            
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        
        priority_queue<int> p; // max heap so that the ans can be sorted in dreasing order
        
        while(pq.size() > 0)
        {
            p.push(pq.top().second);
            pq.pop();
        }
        
        while(p.size() > 0)
        {
            ans[k - 1] = p.top(); // kyuki ans ascending order mein chahiye, toh last index mein largest value(p is the max heap)
            p.pop();
            k--;
        }
        
        return ans;        
    }
};