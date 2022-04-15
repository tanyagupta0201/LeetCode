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

// Using Level Order Traversal
class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int maxVal = INT_MIN;
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                maxVal = max(maxVal, node->val);
                
                if(node->left !=  NULL)
                    q.push(node->left);
                
                if(node->right != NULL)
                    q.push(node->right);              
            }
            
            ans.push_back(maxVal);
        }
        
        return ans;
    }
};