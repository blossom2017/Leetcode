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
    TreeNode * util(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        if(!root)return NULL;
        if(root->val==p->val||root->val==q->val)return root;
        
        TreeNode * left=util(root->left,p,q);
        TreeNode * right=util(root->right,p,q);
        if(left&&right)return root;
        if(!left)return right;
        else return left;
            
    }
bool found(TreeNode * root, TreeNode * p)
{
    queue<TreeNode *> q;
    if(!root)return false;
    q.push(root);
    while(!q.empty())
    {
        TreeNode * front= q.front();
        if(front->val==p->val)return true;
        q.pop();
        if(front->left)q.push(front->left);
        if(front->right)q.push(front->right);
    }
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode * lca= util(root,p,q);
   //     if(found(root,p)&&found(root,q))return lca;
     //   else return NULL;
        return lca;
        
    }
};
