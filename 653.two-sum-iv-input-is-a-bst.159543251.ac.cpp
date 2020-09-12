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
    void inorder(TreeNode * root,vector<int> &res)
    {
        if(!root)return ;
        if(root->left)inorder(root->left,res);
        res.push_back(root->val);
        if(root->right)inorder(root->right,res);
    }
    bool findTarget(TreeNode* root, int k) {
        if((!root->left&&!root->right)||!root)return false;
        vector<int> res;
        inorder(root,res);
        int i=0;
        int j=res.size()-1;
        while(i<res.size()&&j>=0&&i<j)
        {
            
            cout<<res[i]<<" "<<res[j]<<endl;
            if(res[i]+res[j]==k)return true;
            else if(res[i]+res[j]<k)i++;
            else j--;
        }
        return false;
        
    }
};
