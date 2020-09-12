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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode * dummy=new ListNode (-1);
        ListNode * res =dummy;
        while(l1&&l2)
        {
            ListNode * nn = new ListNode ((l1->val+l2->val+c)%10);
            c=(l1->val+l2->val+c)/10;
            dummy->next = nn;
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
            
        }
        if(l1)
        {
            while(l1)
            {
                 ListNode * nn = new ListNode ((l1->val+c)%10);
            c=(l1->val+c)/10;
            dummy->next = nn;
            dummy=dummy->next;
                l1=l1->next;
            }
        }
        else if(l2)
        {
           while(l2)
            {
                 ListNode * nn = new ListNode ((l2->val+c)%10);
            c=(l2->val+c)/10;
            dummy->next = nn;
            dummy=dummy->next;
               l2=l2->next;
            } 
        }
        if(c)
        {
             ListNode * nn = new ListNode (c);
            dummy->next = nn;
            
        }
        return res->next;
        
    }
};
