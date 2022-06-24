class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<long long> maxh;
        long long sum = 0;
        
        for (auto &e : target)
        {
            sum += e;
            maxh.push(e);
        }

        while (maxh.top() != 1)
        {
            long long maxi = maxh.top();
            maxh.pop();

            long long rem = sum - maxi;

            if (rem == 1)
                return true;

            if (maxi <= rem || rem == 0)
                return false;

            long long newMx = maxi % rem;

            if (newMx == 0)
                return false;

            maxh.push(newMx);
            sum = rem + newMx;
        }
        
        return true;
    }
};