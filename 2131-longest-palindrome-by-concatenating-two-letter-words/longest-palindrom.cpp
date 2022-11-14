/*
lets say we have two string ,reverse of each other ,
Now if we have a palindrome and we add one string to front and it and another at back, it will still be a palindrome .
(len += 4 in our case) Also if all the pairs are made , we can still increase length by putting a string in between but both the char of string should be same.

TC = SC = O(N)
*/

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int res = 0;
        unordered_map<string, int> hm;

        for (string s : words)
        {
            // match to make pairs that can be taken in palindrome
            string p = s;
            reverse(p.begin(), p.end());

            if (hm[p] > 0)
            {
                // reverse of current string found, these 2 strings can be added to palindrome
                res += 4;
                hm[p]--; // remove occurence of string as we used it for palindrome
            }
            else
            {
                hm[s]++; // reverse not fount , put it in hashmap
            }
        }
        //***** to take element at the center with both letters same
        for (auto i : hm)
        { // only strings with frequency 1 are left now
            if (i.first[0] == i.first[1] && i.second > 0)
            {
                // to place in center of palindrome we needs chars to be same
                return res + 2;
            }
        }

        return res;
    }
};