// Problem Link: https://leetcode.com/problems/koko-eating-bananas/

// YouTube Link: https://youtu.be/LzZFUTWE55c

// Binary Search

class Solution
{
public:
    bool isPossible(vector<int> piles, int h, int sp)
    {
        int time = 0;

        for (int i : piles)
        {
            // We need ceil value, suppose we get 2.3 so koko need to spend 3 hrs there but integer value will give 2 hrs as answer
            time += (int)ceil(1.0 * i / sp);
        }

        if (time <= h)
            return true;
        return false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int maxi = INT_MIN;

        for (int i : piles)
        {
            maxi = max(i, maxi);
        }

        // Agar number of hours  number of piles ke equal diye hue hain toh maximum value hi leni padegi usse choti value le hi nahi sakte
        if (h == piles.size())
            return maxi;

        int low = 1, high = maxi;
        int speed = INT_MIN;

        while (low <= high)
        {
            int sp = low + (high - low) / 2; // to avoid overflow

            if (isPossible(piles, h, sp) == true)
            {
                speed = sp;
                high = sp - 1;
            }
            else
            {
                low = sp + 1;
            }
        }
        return speed;
    }
};
