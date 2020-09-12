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
    void pathsumutil(TreeNode * root, int &ans,int k,vector<int > &path)
    {
        if(!root)return ;
        path.push_back(root->val);
        pathsumutil(root->left,ans,k,path);
        pathsumutil(root->right,ans,k,path);
        int f=0;
        for(int i=path.size()-1;i>=0;i--)
        {
            f+=path[i];
            if(f==k)ans++;
        }
        path.pop_back();
        
    }
    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        vector<int > path;
        pathsumutil(root,ans,sum,path);
        return ans;
        
    }
};
