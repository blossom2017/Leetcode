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
    int util(TreeNode * A,bool &ans)
{
    if(!A)return 0;
    if(!A->left&&!A->right)return 1;
    int lh = util(A->left,ans);
    int rh = util(A->right,ans);
    if(abs(rh-lh)>1)ans = false;
    return 1+max(lh,rh);
    
}
    bool isBalanced(TreeNode* A) {
        bool ans = true;
    int x=util(A,ans);
   return ans;
        
    }
};
