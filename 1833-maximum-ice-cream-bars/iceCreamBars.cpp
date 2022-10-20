class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());

        for (int i = 0; i < costs.size(); i++)
        {
            // jis point par coins less than zero ho jayenge uss point par hum total icecreams return kardenge
            if ((coins -= costs[i]) < 0)
            {
                return i;
            }
        }

        // otherwise he can buy all the ice creams
        return costs.size();
    }
};