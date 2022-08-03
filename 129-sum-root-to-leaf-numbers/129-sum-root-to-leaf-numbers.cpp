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
           /*
            for(int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
            }
            cout << " ";
            */
            return;
        }
        
        if(root->left)
        {
            getPath(root->left, ans, res + to_string(root->left->val));
        }
        
        if(root->right)
        {
            getPath(root->right, ans, res + to_string(root->right->val));
        }
    }
    
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        vector<string> ans;
        
        if(root == NULL)
            return sum;
        
        string res = to_string(root->val);
        getPath(root, ans, res);
        
        for(auto i : ans)
        {
            sum += stoi(i);
        }
        return sum;
        
    }
};