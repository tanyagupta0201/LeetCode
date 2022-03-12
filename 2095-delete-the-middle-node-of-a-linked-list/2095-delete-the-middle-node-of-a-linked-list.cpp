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
    ListNode* deleteMiddle(ListNode* head) 
    {
        // If there is a single node, we need to delete it and return NULL
        if(head->next == NULL)
            return NULL;
        
        ListNode *fast = head, *slow = head, *prev = slow;
        
        // Find middle of the Linked List
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};