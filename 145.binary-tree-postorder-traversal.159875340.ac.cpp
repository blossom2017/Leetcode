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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        stack<int> st2;
        vector<int> ans;
        if(!root)return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode * tp = st.top();
            st.pop();
            st2.push(tp->val);
            if(tp->left)st.push(tp->left);
            if(tp->right)st.push(tp->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
 
    
    }
};
