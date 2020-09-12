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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)return head;
       ListNode * dummy = new ListNode(-1);
       
		ListNode * cur = head;
		
		ListNode * pre = dummy; //insert node between pre and pre.next
		ListNode* next = NULL; //the next node will be inserted
		//not the end of input list
		while( cur){
			next = cur->next;
			//find the right place to insert
			while( pre->next&& pre->next->val < cur->val ){
				pre = pre->next;
			}
			//insert between pre and pre.next
			cur->next = pre->next;
			pre->next = cur;
			pre = dummy;
			cur = next;
		}
		
		return dummy->next;
        
    }
};
