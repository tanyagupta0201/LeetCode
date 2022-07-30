class Solution {
public:
    string removeDigit(string number, char digit)
    {
        string maxi = "";
        
        for(int i = 0; i < number.size(); i++)
        {
            if(digit == number[i])
            {
                string temp = number.substr(0, i) + number.substr(i + 1);
                
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};