// Hamesha left se replace hoga kyuki lexicographically smallest wahin se check honi start hoti hai
// We will find the non 'a' character if found, we will replace it with a
// if no 'a' character found, that is all 'a' then replace the last character with 'b'
// check only till n/2 because after that characters will be repeating
// if length is 1 or less than 1, delete that and return empty string

class Solution
{
public:
    string breakPalindrome(string s)
    {
        int n = s.length();

        if (n <= 1)
            return "";

        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != 'a')
            {
                s[i] = 'a';
                return s;
            }
        }

        // all a's in the string, replace last char with 'b'
        s[n - 1] = 'b';

        return s;
    }
};