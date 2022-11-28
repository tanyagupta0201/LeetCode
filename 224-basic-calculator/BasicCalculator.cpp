class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int answer = 0;
        long long current_val = 0, sign = 1;

        for (char c : s)
        {
            if (isdigit(c))
            {
                current_val = 10 * current_val + c - '0';
            }

            else if (c == '+')
            {
                answer += current_val * sign;
                current_val = 0;
                sign = 1;
            }

            else if (c == '-')
            {
                answer += current_val * sign;
                current_val = 0;
                sign = -1;
            }

            else if (c == '(')
            {
                st.push(answer);
                st.push(sign);
                answer = 0;
                sign = 1;
            }

            else if (c == ')')
            {
                answer += current_val * sign;
                current_val = 0;

                answer = answer * st.top();
                st.pop();
                answer = answer + st.top();
                st.pop();
            }
        }

        answer += current_val * sign;
        return answer;
    }
};