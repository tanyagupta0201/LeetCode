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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        TreeNode* newNode = new TreeNode();
        
        // If node does not exists in both the trees
        if(root1 == NULL && root2 == NULL)
            return NULL;
        
        // When nodes exsits in both the trees
        if(root1 && root2)
        {
            newNode->val = root1->val + root2->val;
        }
        // If node exsits in tree1 but not in tree2
        else if(root1)
        {
            newNode->val = root1->val;
        }
        // If node exsits in tree2 but not in tree1
        else if(root2)
        {
            newNode->val = root2->val;
        }
        
        // Recursively assigning right and left pointers
        newNode->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        newNode->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
        
        return newNode;
    }
};