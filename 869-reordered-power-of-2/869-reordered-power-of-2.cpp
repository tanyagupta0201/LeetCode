/*

The easiest way to check if two things are shuffled versions of each other, which is what this problem is asking us to do, is to sort them both and the compare the result.

In that sense, the easiest solution here is to do exactly that: we can convert N to an array of its digits, sort it, then compare that result to the result of the same process on each power of 2.

Since the constraint upon N is 10e9, we only need to check powers in the range [0,29].

*/

class Solution
{
public:
    bool reorderedPowerOf2(int N)
    {
        string res1 = to_string(N);
        sort(res1.begin(), res1.end());
        
        for (int i = 0; i < 30; i++)
        {
            string res2 = to_string(1 << i);
            
            sort(res2.begin(), res2.end());
            
            if (res1 == res2)
                return true;
        }
        
        return false;
    }
};