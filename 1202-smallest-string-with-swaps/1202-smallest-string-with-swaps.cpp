class Solution
{
private:
    void initialize(vector<int> &parent, int n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }
    
    void _union(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int x_rep = find(parent, x);
        int y_rep = find(parent, y);

        if (x_rep == y_rep)
            return;

        if (rank[x_rep] < rank[y_rep])
            parent[x_rep] = y_rep;
        else if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        initialize(parent, n);

        for (auto &v : pairs)
        {
            int x = find(parent, v[0]);
            int y = find(parent, v[1]);
            
            if (x != y)
                _union(parent, rank, x, y);
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < s.length(); i++)
            mp[find(parent, i)].push_back(i);

        for (auto &v : mp)
        {
            string tmp = "";
            int i = 0;
            for (int u : v.second)
                tmp.push_back(s[u]);
            sort(tmp.begin(), tmp.end());
            for (int u : v.second)
                s[u] = tmp[i++];
        }
        
        return s;
    }
};