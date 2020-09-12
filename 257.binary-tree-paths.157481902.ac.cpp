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
    void util(vector<string > &ans, string path,TreeNode * root)
    {
        if(!root)return ;
        else if(!root->left&&!root->right)
        {
             path+=to_string(root->val);
           
           
            ans.push_back(path);
        }
       // string pathx=path;
        path+=to_string(root->val);
        path.push_back('-');
        path.push_back('>');
        
        util(ans,path,root->left);
        util(ans,path,root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string > ans;
        string path;
        util(ans,path,root);
        return ans;
    }
};
