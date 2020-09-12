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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * pre=dummy;
        ListNode * ptr = head;
        while(ptr)
        {
            if(ptr->val==val)
            {
                pre->next = ptr->next;
                ptr=pre->next;
            }
            else
            {
                ptr=ptr->next;
                pre= pre->next;
            }
        }
        return dummy->next;
        
    }
};
