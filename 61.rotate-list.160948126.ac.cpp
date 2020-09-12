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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        int size=0;
        ListNode * ptr =head;
        while(ptr)
        {
            ptr=ptr->next;
            size++;
        }
        k=k%size;
        if(k==0)return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next=head;
      ListNode*  slow=dummy;
        ListNode *fast=dummy;
        for(int i=1;i<=k+1;i++)fast=fast->next;
        ListNode * pre =NULL;
        while(fast)
        {
            pre=fast;
            fast=fast->next;
            slow=slow->next;
        }
        cout<<slow->val<<" ";
       if(pre)
       {
           ListNode *temp=slow->next;
           pre->next=dummy->next;
        dummy->next =temp;
           slow->next=NULL;
        
       }
        
        return dummy->next;
    }
};
