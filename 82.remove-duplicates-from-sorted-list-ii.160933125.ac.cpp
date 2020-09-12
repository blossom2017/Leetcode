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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head||!head->next)return head;
        ListNode * dummy =new ListNode(-1);
        dummy->next=head;
        ListNode * pre=dummy;
        ListNode * ptr=head;
        ListNode * ptrn=head->next;
        while(ptrn)
        {
            if(ptrn->val==ptr->val)ptrn=ptrn->next;
            else if(pre->next->next!=ptrn)
            {
                pre->next=ptrn;
                ptr=ptrn;
                ptrn=ptrn->next;
            }
            else 
            {
                ptrn=ptrn->next;
                ptr=ptr->next;
                pre=pre->next;
            }
        }
        if(pre->next->next!=ptrn)
            {
                pre->next=ptrn;
               
                
            }
        return dummy->next;
        
    }
};
