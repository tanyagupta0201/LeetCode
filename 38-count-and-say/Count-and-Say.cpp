class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";

        // we will generate current n's answer from (n - 1)
        for (int i = 2; i <= n; i++)
        {
            string lastStr = ans;
            int len = ans.size(); // we cannot move beyond len
            int j = 0;            // we will always start from Zero for every new number
            ans = "";             // for every number a new answer will be generated

            while (j < len)
            {
                int cnt = j;

                while (j < len && lastStr[j] == lastStr[cnt])
                {
                    cnt++;
                }

                ans += to_string(cnt - j) + lastStr[j]; // freq of character(continous) + that character
                j = cnt;
            }
        }
        return ans;
    }
};