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
   void inorder(TreeNode * root,vector<int> &ans)
   {
       if(!root)return ;
       if(root->left)inorder(root->left,ans);
       ans.push_back(root->val);
       if(root->right)inorder(root->right,ans);
   }
    int getMinimumDifference(TreeNode* root) {
      vector<int > ans;
        inorder(root,ans);
        int mindiff = INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            mindiff= min(mindiff,abs(ans[i+1]-ans[i]));
        }
        return mindiff;
        
    }
};
