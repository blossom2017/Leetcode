/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        queue<TreeLinkNode * > q;
        q.push(root);
        while(!q.empty())
        {
            int size =q.size();
            while(size)
            {
            TreeLinkNode * front = q.front();
            q.pop();
            if(size==1)front->next=NULL;
            else 
            {
                TreeLinkNode * nn= q.front();
                front->next =nn;
                
            }
                
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
                size--;
            }
        }
        
    }
};
