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
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        ListNode *dummy = head;

        int len = 0;
        while (dummy != NULL)
        {
            len++;
            dummy = dummy->next;
        }

        int ans = 0;
        while (head != NULL)
        {
            int t = head->val * pow(2, len - 1);
            ans += t;
            len--;
            head = head->next;
        }

        return ans;
    }
};