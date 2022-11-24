/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void swap(vector<int> &arr, int i, int j)
    {
        int t;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    int minSwaps(vector<int> &arr)
    {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        int swaps = 0;

        unordered_map<int, int> mp;

        // element -> index of the original array
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;
        }

        // now compare the elements in original and sorted array
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != temp[i])
            {
                swaps++;
                int currEle = arr[i];

                swap(arr, i, mp[temp[i]]); // swap in original array

                // now update indices in the map
                mp[currEle] = mp[temp[i]];
                mp[temp[i]] = i;
            }
        }

        return swaps;
    }

    int minimumOperations(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);

                level.push_back(node->val);
            }
            ans += minSwaps(level);
        }

        return ans;
    }
};