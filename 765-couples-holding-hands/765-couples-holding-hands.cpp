class Solution {
public:
    int minSwapsCouples(vector<int>& row)
    {
        map<int, int> mp;
        
        // map the number with its index
        for(int i = 0; i < row.size(); i++)
        {
            mp[row[i]] = i;
        }
        
        int ans = 0;
        
        for(int i = 0; i < row.size(); i += 2)
        {
            int first = row[i];
            int second = first + (first % 2 == 0 ? 1 : -1); // expected partner
            
            if(second != row[i + 1])  // expected partner does not match
            {
                int temp = row[i + 1];
                row[i + 1] = second;  // put correct partner on its place
                
                int idx = mp[second];  // correct index
                row[idx] = temp; // put incorrect partner on the correct partner's index
                
                mp[second] = i + 1;     // Update the map with updated swap
                mp[temp] = idx;
                
                ans++;
            }           
        }
        return ans; 
    }
};