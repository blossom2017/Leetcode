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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode * > q;
        if(!root)return ans;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while(size--)
            {
                TreeNode * front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
