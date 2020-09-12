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
    void inorder(TreeNode * root, int &ct,int &maxfre, TreeNode* &prev)
    {
        cout<<"kkkk";
        if(!root)return;
        if(root->left)inorder(root->left,ct,maxfre,prev);
        if(prev!=NULL&&root->val==prev->val)
        {
            ct++;
            maxfre=max(ct,maxfre);
        }
        else if(prev!=NULL&&root->val!=prev->val)
        {
            ct=1;
            maxfre=max(ct,maxfre);
        }
        else if(prev==NULL)ct=1;
        prev=root;
       if(root->right)inorder(root->right,ct,maxfre,prev);
        
    }
    void nextpass(TreeNode* root, int &ct, int maxfre, vector<int> &ans,TreeNode * &prev)
    {
        //cout<<"jjjj";
        if(!root)return;
        if(root->left)nextpass(root->left,ct,maxfre,ans,prev);
        if(prev!=NULL&&root->val==prev->val)
        {
            ct++;
           // cout<<"xxxx";
            if(ct==maxfre)ans.push_back(root->val);
        }
        else if(prev!=NULL&&root->val!=prev->val)
        {
            ct=1;
            if(ct==maxfre)ans.push_back(root->val);
        }
        else if(prev==NULL)
        {
            ct=1;
            if(ct==maxfre)ans.push_back(root->val);
        }
        prev=root;
      if(root->right)nextpass(root->right,ct,maxfre,ans,prev);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        int ct =0;
        TreeNode * prev = NULL;
        int maxfre =1;
        inorder(root,ct,maxfre,prev);
       // cout<<"here"<<" "<<maxfre;
        ct=0;
        prev=NULL;
        nextpass(root,ct,maxfre,ans,prev);
        return ans;
        
    }
};
