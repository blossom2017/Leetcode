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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * a= l1;
        ListNode * b=l2;
        if(!l1)return l2;
        if(!l2)return l1;
        bool flag =true;
       
       ListNode * dummy = new ListNode(-1);
         ListNode * pre=dummy;
        while(a&&b)
        {
            if(a->val<=b->val)
            {
                dummy->next=a;
                
                a=a->next;
                dummy=dummy->next;
            }
            else
            {
                dummy->next=b;
                b=b->next;
                dummy=dummy->next;
            }
        }
        if(a)dummy->next=a;
        else if(b)dummy->next=b;
        return pre->next;
        
    }
};
