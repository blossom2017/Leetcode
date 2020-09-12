/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * tobst(ListNode * head, ListNode * tail)
    {
        if(head==tail)return NULL;
        ListNode * slow = head;
        ListNode * fast = head;
     
        while(fast!=tail&&fast->next!=tail)
        {
         
            fast = fast->next->next;
            slow= slow->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = tobst(head,slow);
        root->right = tobst(slow->next,tail);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        ListNode * tail = NULL;
        return tobst(head,tail);
    }
};
