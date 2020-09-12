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
    int sumutil(TreeNode* root, int & ans)
    {
        if(!root)return 0;
        int ls = 0;
        int rs =0;
        if(!root->left&&!root->right)return root->val;
        ls = sumutil(root->left,ans);
        rs = sumutil(root->right,ans);
        ans+=abs(ls-rs);
        return ls+rs+root->val;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        int vl = sumutil(root,ans);
        return ans;
        
    }
};
