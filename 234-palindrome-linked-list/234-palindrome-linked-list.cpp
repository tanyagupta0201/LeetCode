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
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr = head, *N, *prev = NULL;
        
        while(curr != NULL)
        {
            N = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = N;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
        
        // Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Reverse the second half of the list
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *dummy = head;
        
        while(slow != NULL)
        {
            if(slow->val != dummy->val)
                return false;
            
            slow = slow->next;
            dummy = dummy->next;
        }
        
        return true;
    }
};