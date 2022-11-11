// https://youtu.be/ff8kxXeFhl8

class Solution {
public:
    string orderlyQueue(string s, int k) 
    {
        // for k = 1, we are only putting the first character and appending it backwards
        // so we will be compare all the substrings (of original size) and find the smallest substring
        if(k == 1)
        {
            string temp = s;
            s += s; // append the string

            for(int i = 1; i < temp.size(); i++)
            {
                temp = min(temp, s.substr(i, temp.size()));
            }
            return temp;
        }
        else
        {
            // When k > 1, the string will always be sorted 
            sort(s.begin(), s.end());
            return s;
        }
    }
};