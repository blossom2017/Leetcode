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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> st(G.begin(),G.end());
        int res = 0;
        while(head)
        {
            if(st.count(head->val)&&(!head->next||!st.count(head->next->val)))res++;
            head=head->next;
        }
        return res;
        
    }
};
