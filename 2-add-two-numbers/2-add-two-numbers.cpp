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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        int carry = 0; // Initially the carry is zero
        
        while(l1 != NULL || l2 != NULL || carry == 1)
        {
            int sum = 0;
            
            // Add the node's value from l1 if it is not NULL
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add the node's value from l1 if it is not NULL
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            
            // Update carry, if it is greater than 9
            carry = sum /10;
            
            // add sum % 10 to new node as it containing the sum
            ListNode* newNode = new ListNode(sum % 10);
            
            temp->next = newNode;
            temp = temp->next;
        }
        
        return dummy->next;        
    }
};