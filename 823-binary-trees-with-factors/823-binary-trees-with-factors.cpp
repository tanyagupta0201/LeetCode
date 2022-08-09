// https://youtu.be/BRGz8ArRiPA

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        int n = arr.size();
        
        // we need to sort the array because the value of the leaf nodes has to be smaller than root value
        sort(arr.begin(), arr.end());
        
        map<long long int, long long int> mp;
        
        // atleast 1 way is there for all the numbers
        for(int i = 0; i < n; i++)
        {
            mp.insert({arr[i], 1});
        }
        
        // taking iterator for every value because we want the second part of the value (the no. of ways)
        for(int i = 1; i < n; i++)
        {
            long long int cnt = 0;
            auto it3 = mp.find(arr[i]);
            
            for(int j = 0; j < i; j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    auto it1 = mp.find(arr[i] / arr[j]);  // 3->1
                    auto it2 = mp.find(arr[j]); // 2->1
                    
                    if(it1 != mp.end()) // value found
                    {
                        cnt += (it1->second) * (it2->second);
                    }
                }
            }
            
            // now change the number of ways for an element
            it3->second += cnt;
        }
        
        // Find the sum of all the ways
        
        long long sum = 0;
        for(auto it4 = mp.begin(); it4 != mp.end(); it4++)
        {
            sum += it4->second;
        }
        
        return sum % 1000000007;
    }
};