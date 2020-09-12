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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return head;
        if(head->next==head)return head;
        ListNode * fast = head;
        ListNode* slow=head;
        while(fast&&fast->next&&slow)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                fast = head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
            
                
        }
        return NULL;
    }
};
