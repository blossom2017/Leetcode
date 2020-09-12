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
    void util(TreeNode * root, long long int &sum, long long int pathsum)
{
    if(!root)return ;
    if(!root->left&&!root->right)
    {
        pathsum=pathsum*10+root->val;
        sum+=pathsum;
    }
    if(root->left)util(root->left,sum,pathsum*10+root->val);
    if(root->right)util(root->right,sum,pathsum*10+root->val);
    
}
    int sumNumbers(TreeNode* root) {
        long long int sum=0;
    util(root,sum,0);
    return sum;
    }
};
