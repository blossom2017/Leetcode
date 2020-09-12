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
    struct compare
    {
        bool operator()(ListNode *a, ListNode * b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //minheaps
        priority_queue<ListNode *,vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++)
        if(lists[i]!=NULL)pq.push(lists[i]);
        ListNode * ans=NULL;
        ListNode * head=NULL;
        while(!pq.empty())
        {
          //  cout<<"heree";
            ListNode * top = pq.top();
            //cout<<top->val<<" ";
            pq.pop();
            if(!ans)
            {
              
                ans=top;
                  head=ans;
            }
            else 
            {
                ans->next=top;
                ans=ans->next;
            }
            if(top->next)pq.push(top->next);
            
        }
        return head;
        
    }
};
