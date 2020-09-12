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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
        return head;
        ListNode * dummy= new ListNode(-1);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * ptr = head;
        ListNode * ptrn = head->next;
        while(ptrn&&ptr)
        {
           ListNode* temp=ptrn->next;
            ptrn->next=ptr;
            ptr->next=temp;
            pre->next=ptrn;
            pre=ptr;
            ptr=temp;
            if(ptr)ptrn=ptr->next;
        }
        return dummy->next;
    }
};
