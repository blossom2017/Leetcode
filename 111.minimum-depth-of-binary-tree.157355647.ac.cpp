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
    void util(TreeNode * root,int level,int &minlevel)
    {
        if(!root)return ;
        if(!root->left&&!root->right&&level<minlevel)minlevel=level;
        if(root->left)util(root->left,level+1,minlevel);
        if(root->right)util(root->right,level+1,minlevel);
    }
    int minDepth(TreeNode* root) {
        int minlevel=INT_MAX;
        if(!root)return 0;
        util(root,1,minlevel);
        
        return minlevel;
        
    }
};
