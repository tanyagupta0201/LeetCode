// https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996773/C%2B%2B-O(26*N)-or-easy-code-or-highly-understandable-for-beginners-or-beats-100

class Solution {
public:
    long long appealSum(string s) 
    {
        long long n = s.size();
		
		// we store final ans here
        long long ans = 0;
		
		// we iterate over all possible characters
        for(int i = 0; i < 26; i++)
        {
			// last_occurence tells the last time the character appeared
            long long last_occurence = 0;
			
			// here we iterate over the string
            for(int j = 0; j < n; j++)
            {
				// if we find the character at current index then update last_occurence = j+1
                if(s[j] - 'a' == i)
                    last_occurence = j + 1;
				
				// add the number of substrings ending at jth index
                ans += last_occurence;
            }
        }
        
        return ans;
    }
};