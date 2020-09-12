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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode * ptr= head;
        ListNode * ptrn = head->next;
        while(ptrn&&ptr)
        {
            ListNode * temp = ptrn->next;
            ptrn->next = ptr;
          if(ptr==head)  ptr->next=NULL;
            ptr= ptrn;
            ptrn= temp;
            
        }
        return ptr;
        
    }
};
