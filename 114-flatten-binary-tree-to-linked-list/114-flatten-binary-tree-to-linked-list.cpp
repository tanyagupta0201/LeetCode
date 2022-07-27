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
    void flatten(TreeNode* root)
    {
        TreeNode* cur = root;
        
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
                
				while(pre->right)
				{
					pre = pre->right;
				}
                
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
            
			cur = cur->right;
		}
        
    }
};