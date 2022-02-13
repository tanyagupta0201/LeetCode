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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* N;
        
        while(curr != NULL)
        {
            // Save the next node
            N = curr->next;
            
            // Make the curr node point to prev
            curr->next = prev;
            
            // Update prev and curr and take 1 step forward
            prev = curr;
            curr = N;
        }
        head = prev;
        return head;
    }
};