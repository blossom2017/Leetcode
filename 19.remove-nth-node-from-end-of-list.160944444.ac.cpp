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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode* ptr = head;
        while(ptr)
        {
            ptr=ptr->next;
            count++;
        }
        int start = count-n;
        ListNode * pre = new ListNode(-1);
        pre->next=head;
        ListNode * dummy = pre;
        ptr=head;
        count=0;
        while(ptr)
        {
            if(count==start)
            {
                dummy->next=ptr->next;
                break;
            }
            else 
            {
                ptr=ptr->next;
                dummy=dummy->next;
                count++;
            }
        }
        return pre->next;
        
    }
};
