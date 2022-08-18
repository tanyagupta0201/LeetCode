class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        
        // [3,3,3,3,5,5,5,2,2,7]
        // 3->4, 5->3, 7->1, 2->2
        for(auto it : arr)
        {
            mp[it]++;
        }
        
        priority_queue<int> pq; // max heap
        // pq -> 4 3 2 1
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push(it->second);
        }
        
        int elements = 0, cnt = 0;
                
        while(cnt < arr.size() / 2)
        {
            elements++; // min number of elements which are to be removed
            
            cnt += pq.top(); // count that element first that has max freq so that min number of elements are removed
            pq.pop();
        }
        
        return elements;
    }
};