// https://youtu.be/h6_lIwZYHQw

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        
        int left[n], right[n];
        
        // initially har bacche ko 1 candy toh milegi hi
        for(int i = 0; i < n; i++)
        {
            left[i] = right[i] = 1;
        }
        
        // left to right
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        
        // right to left
        for(int i = n - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }
        
        // it stores the max of both the values of right and left array
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        
        return sum;
    }
};