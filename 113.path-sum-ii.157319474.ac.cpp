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
    void pathsumutil(TreeNode * root,vector<int > path,vector<vector<int >> &ans,int sum,int k)
    {
        if(!root)return;
        if(!root->left&&!root->right&&sum+root->val==k)
        {
            path.push_back(root->val);
            ans.push_back(path);
        }
        path.push_back(root->val);
        pathsumutil(root->left,path,ans,sum+root->val,k);
        pathsumutil(root->right,path,ans,sum+root->val,k);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int >> ans;
        vector<int > path;
        pathsumutil(root,path,ans,0,sum);
        return ans;
    }
};
