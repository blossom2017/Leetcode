/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //O(N) space
        /*
        map<RandomListNode *, RandomListNode*> mp;
        if(!head)return NULL;
        RandomListNode * cur = head;
        while(cur)
        {
            mp[cur]=new RandomListNode(cur->label);
            cur=cur->next;
        }
        cur=head;
        while(cur)
        {
            RandomListNode * cl= mp[cur];
            cl->next = mp[cur->next];
            cl->random= mp[cur->random];
            cur=cur->next;
        }
        return mp[head];
        */
        //O(1)
        
        if(!head)return NULL;
        RandomListNode * cur = head;
        while(cur)
        {
            RandomListNode * temp= cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = temp;
            cur=temp;
        }
        cur= head;
        while(cur&&cur->next)
        {
            RandomListNode * temp = cur->next->next;
           if(cur->random) cur->next->random=cur->random->next;
            cur = temp;
        }
        RandomListNode * dummy = new RandomListNode(-1);
       RandomListNode * res= dummy;
        cur = head;
        RandomListNode * ptra = head->next;
        while(cur)
        {
            dummy->next = ptra;
            if(ptra->next)ptra=ptra->next->next;
            dummy=dummy->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return res->next;
    }
};
