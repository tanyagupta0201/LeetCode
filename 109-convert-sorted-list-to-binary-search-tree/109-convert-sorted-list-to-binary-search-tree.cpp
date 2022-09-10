/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

/*
    
/*
    USING EXTRA SPACE
    
class Solution {
public:
    TreeNode* helper(vector<int> &v, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            TreeNode *root = new TreeNode(v[mid]);
            
            root->left = helper(v, low, mid - 1);
            root->right = helper(v, mid + 1, high);
            
            return root;
        }
        
        return NULL;
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        
        vector<int> v;
        ListNode *curr = head;
        
        while(curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = v.size();
        //cout << n << endl;
        return helper(v, 0, n - 1);
    }
};

*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
           return new TreeNode(head->val);
           
        ListNode *slow = head, *fast = head, *prev = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        TreeNode *root = new TreeNode(slow->val);
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;        
    }
};