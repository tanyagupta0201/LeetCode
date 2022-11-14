class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }

    string reverseVowels(string s)
    {

        int low = 0, high = s.length() - 1;

        while (low < high)
        {
            if (!isVowel(s[low]))
            {
                low++;
            }
            else if (!isVowel(s[high]))
            {
                high--;
            }
            else
            {
                swap(s[high], s[low]);
                low++;
                high--;
            }
        }
        return s;
    }
};