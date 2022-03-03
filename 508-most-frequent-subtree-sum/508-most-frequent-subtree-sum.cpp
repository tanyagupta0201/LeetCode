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
class Solution {
public:
    int maxSum = -1;
    map<int, int> mp;
    
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        
        maxSum = max(maxSum, ++mp[currSum]);
        
        return currSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {        
        dfs(root);
        vector<int> ans;
        
        for(auto &it: mp)
        {
            if(it.second == maxSum)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};