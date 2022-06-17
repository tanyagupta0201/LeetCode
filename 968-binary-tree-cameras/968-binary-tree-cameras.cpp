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

// https://youtu.be/fORHMo5yzNk
// Corona Vaccine Similar ques on GFG

class Solution {
public:
    int camera = 0;
    
    string solve(TreeNode* root)
    {
        if(root == NULL)
            return "ok"; // no root, no camera needed 
        
        string left = solve(root->left);
        string right = solve(root->right);
        
        if(left == "want" || right == "want")
        {
            camera++;
            return "provide"; // the parent will provide camera if any child needs
        }
        else if(left == "provide" || right == "provide")
        {
            return "ok"; // parent is ok as it is getting covered
        }
        
        return "want"; // last case that parent wants       
    }
    
    int minCameraCover(TreeNode* root) 
    {
        if(solve(root) == "want")
            camera++;
        
        return camera;        
    }
};