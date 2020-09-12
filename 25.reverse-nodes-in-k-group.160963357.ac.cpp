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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next)return head;
        ListNode * ptr=head;
        int count =0;
        ListNode * pre = new ListNode(-1);
        ListNode* dummy=pre;
        pre->next = head;
        while(ptr)
        {
            ListNode * st =ptr;
            ListNode * end = ptr;
            while(end&&count<k)
            {
             //  cout<<end->val<<" ";  
                count++;
                end=end->next;
            }
            //cout<<count<<" ";
            if(count<k)break;
           // cout<<end->val<<" bbb";
            ListNode * ptrn = ptr->next;
            ListNode * prev= NULL;
            
            int ct=1;
            while(ptrn&&ct<k)
            {
                 ct++;
              ListNode * temp = ptrn->next;
                ptrn->next=ptr;
                ptr->next=prev;
                prev=ptr;
                ptr=ptrn;
                ptrn=temp;
            }
           
            pre->next=ptr;
            st->next=ptrn;
            ptr=st->next;
            pre=st;
          // cout<<ptr->val<<" jj";
            count=0;
        }
        return dummy->next;
        
        
    }
};
