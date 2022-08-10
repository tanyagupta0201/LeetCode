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
    ListNode* mergeNodes(ListNode* head) 
    {
        head = head->next;
        ListNode *start = head;
        
        while(start != NULL)
        {
            ListNode *end = start;
            int sum = 0;
            
            while(end->val != 0)
            {
                sum += end->val;
                end = end->next;
            }
            
            start->val=sum;   /*assign sum to first node between two 0*/
            start->next=end->next;   /*make this connect to first node of next part*/
            start=start->next;    /*go..to..next..part*/
        }
        return head;
    }
};