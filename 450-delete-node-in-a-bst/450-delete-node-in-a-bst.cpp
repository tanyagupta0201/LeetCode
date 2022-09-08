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
    // Find last right node of left subtree
    TreeNode *findLastRight(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        
        return findLastRight(root->right);
    }
    
    TreeNode* helper(TreeNode* root)
    {        
        // right subtree does not exist
        if(root->right == NULL)
            return root->left;
        
        // left subtree does not exist
        if(root->left == NULL)
            return root->right;
        
        // Both subtrees exist
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        
        lastRight->right = rightChild;
        
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return NULL;
        
        if(key == root->val)
            return helper(root);
        
        TreeNode *dummy = root;
        
        while(root != NULL)
        {
            if(key < root->val) // go left
            {
                if(root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else // go right
            {
                if(root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }                
            }
        }
        
        return dummy;
    }
};