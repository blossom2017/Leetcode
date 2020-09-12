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
        ListNode * ptr= head;
        ListNode * ptrn= head->next;
        while(ptrn&&ptr)
        {
            if(ptr->val==ptrn->val)
            {
                ptr->next=ptrn->next;
                ptrn=ptr->next;
            }
            else 
            {
                ptrn=ptrn->next;
                ptr=ptr->next;
            }
        }
        return head;
        
    }
};
