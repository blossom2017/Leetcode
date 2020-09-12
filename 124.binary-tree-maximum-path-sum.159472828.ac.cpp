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
    int max(int a, int b, int c ,int d)
    {
        if(a>=b&&a>=c&&a>=d)return a;
        else if(b>=a&&b>=c&&b>=d)return b;
        else if(c>=a&&c>=b&&c>=d)return c;
        else return d;
    }
   
        
    int maxutil( TreeNode * root, int &maxsum)
{
    int ls=0,rs=0;
    if(!root)return 0;
         if(!root->left&&!root->right)
         {
             if(root->val>maxsum)maxsum=root->val;
             return root->val;
         }
    if(root->left)ls=maxutil(root->left,maxsum);
    if(root->right)rs=maxutil(root->right,maxsum);
   
  int mxval = max(ls+rs+root->val,ls+root->val,rs+root->val,root->val);
    //    cout<<mxval<<" ";
     if(mxval>maxsum)maxsum = mxval;
      //  cout<<maxsum<<" ";
    return max(ls+root->val,rs+root->val,root->val,INT_MIN);
}
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
maxutil(root,maxsum);
return maxsum;
    }
};
