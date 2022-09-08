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
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
             return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);             
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> res;
        
        if(root1 == NULL && root2 == NULL)
            return res;
        
        vector<int> v1, v2;
        
        inorder(root1, v1);
        inorder(root2, v2);
        
        // Merge sort
        int i = 0, j = 0;
        
        while(i < v1.size() && j < v2.size())
        {
            if(v1[i] < v2[j])
            {
                res.push_back(v1[i]);
                i++;
            }
            else
            {
                res.push_back(v2[j]);
                j++;
            }
        }
        
        while(i < v1.size())
        {
            res.push_back(v1[i]);
            i++;
        }
        
        while(j < v2.size())
        {
            res.push_back(v2[j]);
            j++;
        }
        
        return res;        
    }
};