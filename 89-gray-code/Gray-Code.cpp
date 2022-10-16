// TC = 2 ^ n
class Solution
{
public:
    vector<string> generate(int n)
    {
        if (n == 1)
        {
            return {"0", "1"};
        }

        vector<string> ans;
        // Recursively generate the gray code for (n - 1)
        vector<string> temp = generate(n - 1);

        // There is a difference of only 1 bit
        // so, as we are generating the answer from the previous number
        // we will first add 0 and then 1 as adding the same bit to every number will result in the difference of only 1 bit
        // the two groups will be grey codes among themselves
        // but to create 2 groups as a whole gray code, we need to reverse the second group otherwise there would be a difference of 2 bits
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back("0" + temp[i]);
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back("1" + temp[i]);
        }

        return ans;
    }

    vector<int> grayCode(int n)
    {
        vector<int> ans;                         // will store the final answer in decimal form
        vector<string> grayString = generate(n); // stores the answer in binary form

        // convert binary to decimal
        for (auto it : grayString)
        {
            // stoi(string, position, int base)
            // int base defines the numerical base for the string.
            // As examples, we have 2 for binary, 16 for hexadecimal, and 10 for base 10.
            ans.push_back(stoi(it, 0, 2));
        }

        return ans;
    }
};