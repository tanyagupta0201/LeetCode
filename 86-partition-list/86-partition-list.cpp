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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* small = new ListNode(0);
        ListNode* greater = new ListNode(0);
        
        ListNode* smallHead = small;
        ListNode* greaterHead = greater;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                // smaller values list
                smallHead->next = head;
                smallHead = smallHead->next;
            }
            else
            {
                // greater values list
                greaterHead->next = head;
                greaterHead = greaterHead->next;
            }
            
            head = head->next;
        }
        
        greaterHead->next = NULL;
        smallHead->next = greater->next;
        
        return small->next;
    }
};