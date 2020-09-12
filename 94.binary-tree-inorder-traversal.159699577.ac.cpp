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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
        stack<TreeNode*> st;
        if(!root)return ans;
       // st.push(root);
        TreeNode * cur = root;
        while(1)
        {
            while(cur)
            {
            st.push(cur);
                cur=cur->left;
            }
            if(cur==NULL&&!st.empty())
            {
                TreeNode * f= st.top();
                st.pop();
                ans.push_back(f->val);
                cur=f->right;
            }
            else if(cur==NULL)break;
        }
        return ans;
        
        
    }
};
