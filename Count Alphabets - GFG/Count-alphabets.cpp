
int Count(string s)
{
    // complete the function here
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            cnt++;
        }
    }

    return cnt;
}