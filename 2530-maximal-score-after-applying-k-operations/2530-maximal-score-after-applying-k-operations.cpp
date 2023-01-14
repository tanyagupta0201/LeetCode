class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<long long> pq{nums.begin(), nums.end()};

        long long score = 0;

        while (k--)
        {
            int mx = pq.top();
            pq.pop();

            score += mx;
            pq.push(ceil((double)mx / 3));
        }

        return score;
    }
};