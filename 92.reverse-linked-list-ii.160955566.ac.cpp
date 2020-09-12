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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count =0;
        if(!head||!head->next)return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next=head;
       
        ListNode * ptr=dummy;
        ListNode * pre =NULL;
        while(ptr)
        {
            if(count==m-1)
            {
                pre=ptr;
                ptr=ptr->next;
                count++;
            }
            else if(count==m)
            {
                cout<<ptr->val<<" ";
           
            
                ListNode* st =ptr;
                ListNode* ptrn = ptr->next;
                while(count<n)
                {
                    ListNode * temp = ptrn->next;
                    ptrn->next=ptr;
                    ptr=ptrn;
                    ptrn=temp;
                    count++;
                }
                
                pre->next= ptr;
                st->next=ptrn;
                break;
            
            }
            else
            {
                ptr=ptr->next;
                count++;
            }
        }
        return dummy->next;
        
    }
};
