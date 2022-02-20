// https://youtu.be/ihd533sQlaU

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* a1;
        ListNode* b1;
        ListNode* curr = list1;
        int count = 1;
        
        // Original a se ek pehle jaana hai aur original b ke ek baad jana hai
        while(curr != NULL)
        {
            if(count == a)
                a1 = curr;
            
            if(count == b)
                b1 = curr->next->next;
            
            count++;
            curr = curr->next;
        }
        
        a1->next = list2;
        curr = list2;
        
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        
        curr->next = b1;
        return list1;
    }
};