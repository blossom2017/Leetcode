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
    bool isValid(TreeNode * root, TreeNode * &prev)
    {
        if(!root)return true;
        if(!(isValid(root->left,prev)))return false;
        if(prev!=NULL&&prev->val>=root->val)return false;
        prev= root;
        return isValid(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
     TreeNode * prev = NULL;
       return isValid(root,prev);
        
    }
};
