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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy, *prev = dummy, *N = dummy;
        int size = 0;
        
        // Calculate the size of the Linked List
        while(curr->next != NULL)
        {
            size++;
            curr = curr->next;            
        }
        
        while(size >= k)
        {
            curr = prev->next; // First node of the first group of the linked list 
            N = curr->next;    // Second node of the first group of the linked list
            
            for(int i = 1; i < k; i++)
            {
                curr->next = N->next;
                N->next = prev->next;
                prev->next = N;
                N = curr->next;
            }
            
            prev = curr;
            size = size - k;
        }
        
        return dummy->next;
    }
};