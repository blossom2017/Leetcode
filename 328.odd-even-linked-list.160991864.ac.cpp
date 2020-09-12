/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return head;
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * a =odd;
        ListNode * pre;
        ListNode * b = even;
        while(a&&b&&a->next&&b->next)
        {
            a->next = a->next->next;
            b->next = b->next->next;
            pre = a;
            a=a->next;
            b=b->next;
        }
        if(!a)pre->next = even;
        else a->next = even;
        return odd;
        
    }
};
