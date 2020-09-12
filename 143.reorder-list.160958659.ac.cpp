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
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return;
       ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode* pre;
        while(fast&&fast->next)
        {
            pre=slow;
            fast=fast->next->next;
            slow = slow->next;
        }
        ListNode * st ;
        ListNode * ptrn = slow;
        ListNode * ptr = NULL;
        ListNode * temp;
        pre->next=NULL;
        while(ptrn)
        {
            cout<<ptrn->val<<" ";
            temp=ptrn->next;
            ptrn->next=ptr;
            ptr= ptrn;
            ptrn=temp;
        }
        
        ListNode * l=dummy;
        st=ptr;
        while(head&&st)
        {
            dummy->next= head;
            head=head->next;
            dummy=dummy->next;
            dummy->next = st;
            st=st->next;
            dummy= dummy->next;
        }
        if(head)dummy->next=head;
        else if(st)dummy->next = st;
        head= l->next;
    }
};
