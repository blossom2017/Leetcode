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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        vector<int> ans;
        if(!root)return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* tp = st.top();
            ans.push_back(tp->val);
            st.pop();
           
            if(tp->right)st.push(tp->right);
             if(tp->left)st.push(tp->left);
        }
        return ans;
        
    }
};
