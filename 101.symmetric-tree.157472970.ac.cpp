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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode * > q;
        stack<TreeNode*> st;
        if(!root)return true;
        q.push(root);
        st.push(root);
        string str;
        str+=to_string(root->val);
        while(!q.empty())
        {
            int size=q.size();
        //    cout<<q.size()<<" "<<st.size()<<" "<<endl;
           queue<TreeNode *> st2;
            while(size--)
            {
                TreeNode * front= q.front();
                TreeNode * top = st.top();
                st.pop();
                q.pop();
                if(front&&!top)return false;
                if(top&&!front)return false;
                if(!front&&!top)continue;
             //   cout<<front->val<<" "<<top->val<<" "<<endl;
                if(front->val!=top->val)
                {
                   // cout<<front->val<<": "<<top->val;
                    //cout<<"hhh";
                    return false;
                }
                if(front)
                {
                    q.push(front->left);
                    st2.push(front->left);
                    q.push(front->right);
                    st2.push(front->right);
                   
                }
            }
            while(!st2.empty())
            {
             st.push(st2.front());
                st2.pop();
            }
            
            
        }
        return true;
    }
};
