/*

Explanation:
As we know the array represents a permutation of the integers in the range [0, n - 1]. So after sorting the array the value at any INDEX will be equal to the value of INDEX.

So the idea is to iterate over the array and maintain a MAXIMUM value till current index and whenever the MAXIMUM value and the CURRENT_INDEX value becomes equal we increase the count because if the MAXIMUM & CURRENT_INDEX value becomes equal it means that all the values before the CURRENT_INDEX are smaller than MAXIMUM.

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        int maxi = INT_MIN;
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > maxi)
                maxi = arr[i];
            
            if(maxi == i)
                count++;
        }
        
        return count;
    }
};