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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *odd = head, *even = head->next, *join = head->next;
        
        while(even && even->next)
        {
            odd->next = odd->next->next;   // Create a list with odd indices
            even->next = even->next->next; // Create a list with even indices
            
            odd = odd->next;
            even = even->next;            
        }
        
        odd->next = join; // Join the last node of list with odd indices with 1st even node
        return head;
    }
};