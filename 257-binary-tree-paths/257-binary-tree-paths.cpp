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
    void getPath(TreeNode* root, vector<string> &ans, string res)
    {
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(res);
            return; 
        }
        
        if(root->left != NULL)
        {
            getPath(root->left, ans, res + "->" + to_string(root->left->val));
        }
        
        if(root->right != NULL)
        {
            getPath(root->right, ans, res + "->" + to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;        
        if(root == NULL)
            return ans;
        
        string res = to_string(root->val);
        
        getPath(root, ans, res);
        
        return ans;
    }
};