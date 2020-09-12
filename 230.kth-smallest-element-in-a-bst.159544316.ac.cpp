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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode* cur = root;
        int visct = 0;
        while(cur||!st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            TreeNode * top = st.top();
            st.pop();
            visct++;
            if(visct==k)return top->val;
            cur = top->right;
        }
        return -1;
        
        
    }
};
