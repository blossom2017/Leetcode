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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)return head;
        ListNode* ptr = head;
        ListNode* ql=new ListNode(-1);
        ListNode * t = ql;
        ListNode* qg=new ListNode(-1);
        ListNode* y = qg;
        while(ptr)
        {
            ListNode * temp = ptr->next;
            if(ptr->val<x)
            {
                ql->next=ptr;
                ql=ql->next;
                ql->next =NULL;
        }
            else 
            {
                 qg->next=ptr;
                qg=qg->next;
                qg->next =NULL;
            }
            ptr=temp;
        
    }
        ql->next=y->next;
        return t->next;
    }
};
