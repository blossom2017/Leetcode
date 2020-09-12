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
     TreeNode* clone(TreeNode* root){
            if(root == nullptr)
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
    
    void inorder(TreeNode * root , int &ct)
    {
       // cout<<ct<<"enter ";
        if(!root)return ;
if(root->left)inorder(root->left,ct);
       // cout<<"heree"<<ct<<" ";
        root->val=ct++;
       // cout<<"llll"<<" ";
   if(root->right)inorder(root->right,ct);
    
        
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0)return ans;
       
        vector<vector<TreeNode*>>v(n+1);
        TreeNode * root = new TreeNode(1);
        root->left=NULL;
        root->right=NULL;
        v[1].push_back(root);
        if(n==1)return v[1];
             

        TreeNode * nn = new TreeNode(-1);
         TreeNode * left = new TreeNode(-1);
        nn->left=left;
        nn->right= NULL;
        v[2].push_back(nn);
    // cout<<"llll";
        TreeNode * ny = new TreeNode(-1);
        ny->right = new TreeNode(-1);
        ny->left = NULL;
      v[2].push_back(ny);
        v[0].push_back(NULL);
  
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                
            {
               for(int k=0;k<v[j].size();k++)
               {
                   for(int q=0;q<v[i-j-1].size();q++)
                   {
                       TreeNode * temp = new TreeNode(-1);
                       temp->left = clone(v[j][k]);
                       temp->right = clone(v[i-j-1][q]);
                       v[i].push_back(temp);
                   }
               }
              
            }
            
        }
        
      cout<<v[n].size()<<" ";
        
        for(int i=0;i<v[n].size();i++)
        {
            int ct=1;
         inorder(v[n][i],ct);
           // cout<<v[3][i]->val<<" "<<endl;
            //if(v[3][i]->left)cout<<v[3][i]->val<<"hhh ";
            //if(v[3][i]->right)cout<<v[3][i]->val<<"jjjjj";
            //cout<<endl;
        }
       // cout<<"hhhh";
        return v[n];
    }
};
