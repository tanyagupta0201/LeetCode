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
    // Using level order traversal
    int deepestLeavesSum(TreeNode* root)
    {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            // If queue is not empty, make sum = 0 as it is not the last level
            if(!q.empty())
            {
                sum = 0;
            }
        }
        
        return sum;       
    }
};