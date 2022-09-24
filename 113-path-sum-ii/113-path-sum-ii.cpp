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
    vector<vector<int>> res;
    vector<int> v;
    
    void dfs(TreeNode* root, int targetSum)
    {
        if(root == NULL)
            return;
        
        int value = root->val;
        v.push_back(value);
        
        if(root->left == NULL && root->right == NULL)
        {
           if(targetSum - value == 0)
               res.push_back(v);
        }
        
        dfs(root->left, targetSum - value);
        dfs(root->right, targetSum - value);
        
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root, targetSum);
        return res;
    }
};