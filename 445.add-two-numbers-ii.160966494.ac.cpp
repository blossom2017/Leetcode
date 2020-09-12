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
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        int c=0;
        ListNode * ptra = l1;
        ListNode * ptrb= l2;
        while(ptra)
        {
            s1.push(ptra->val);
            ptra=ptra->next;
        }
        while(ptrb)
        {
            s2.push(ptrb->val);
            ptrb=ptrb->next;
            
        }
        
        while(!s1.empty()||!s2.empty())
        {
            int n1 = (s1.empty())?0:s1.top();
            if(!s1.empty())s1.pop();
            int n2 = (s2.empty())?0:s2.top();
            if(!s2.empty())s2.pop();
            int num = n1+n2+c;
            s3.push(num%10);
            c=num/10;
        }
        if(c)s3.push(c);
        ListNode * d= new ListNode(-1);
        ListNode * temp = d;
        while(!s3.empty())
        {
            int top= s3.top();
            s3.pop();
            ListNode * n= new ListNode(top);
            d->next= n;
            d=d->next;
            
        }
        return temp->next;
    }
};
