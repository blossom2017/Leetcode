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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode * ptr = head;
        ListNode * fast = head;
        while(fast&&fast->next&&ptr)
        {
            fast=fast->next->next;
            ptr= ptr->next;
        }
        ListNode * newstart=ptr;
        ListNode * pre=NULL;
        while(newstart)
        {
            ListNode * temp =newstart->next;
            newstart->next=pre;
            pre = newstart;
            newstart=temp;
        }
        ptr=pre;
    
      //  cout<<ptr->val<<" ";
        while(ptr&&head)
        {
            if(ptr->val!=head->val)return false;
            ptr=ptr->next;
            head=head->next;
        }
        return true;
        
    }
};
