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
class Solution {
public:
    void swap(int i, int j, vector<int> &v)
    {
        int t;
        t = v[i];
        v[i] = v[j];
        v[j] = t;
    }
    
    ListNode* swapNodes(ListNode* head, int k)
    {
        // We can transform the linked list to an array this should ease things up
        // After transforming the linked list to an array it becomes as easy as swapping two integers in an array then 
        // rebuilding the linked list
        ListNode* temp = head;
        
        vector<int> v;
        int size = 0; // size of a linked list
        
        // Build the array
        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
            size++;
        }
        
        // Now aur vector/array is 0 indexed but linked list is 1 based so we need to take care of that
        swap(k - 1, size - k, v);
        
        // Rebuild the Linked List
        ListNode* temp2 = head;
        int i = 0;
        
        while(temp2 != NULL)
        {
            temp2->val = v[i];
            i++;
            temp2 = temp2->next;
        }
        
        // Return head as temp2 becomes NULL
        return head;
    }
};