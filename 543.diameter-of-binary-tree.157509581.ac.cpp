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
    int util(TreeNode * node, int &maxi)
{
    if(!node)return 0;
    if(!node->left&&!node->right)
    {
        if(maxi<1)maxi=1;
        return 1;
    }
    int lh = util(node->left,maxi);
    int rh = util(node->right,maxi);
    if(lh+rh+1>maxi)maxi=lh+rh+1;
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int max =-1;
        if(!root)return 0;
   int x = util(root,max);
   return max-1;
        
    }
};
