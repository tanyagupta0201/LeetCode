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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // Corner Cases
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode* curr = head;
        int len = 1;
        
        // Traverse to the last and increase len, at the end the len stores the length of the linked list
        while(curr->next != NULL && ++len)
            curr = curr->next;
        
        // Point the last node to the first node(head) 
        curr->next = head;
        
        k = k % len;
        k = len - k; // here k stores the first K nodes which are not rotated
        
        // After this loop ends, we reach to the node(curr comes to the node) after which the nodes are rotated
        while(k--)
        {
            curr = curr->next;
        }
        
        head = curr->next;
        curr->next = NULL;
        
        return head;       
    }
};