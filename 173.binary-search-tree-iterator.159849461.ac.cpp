/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }
*/

     
class BSTIterator {
public:
    TreeNode * ptr;
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root) {
       find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       
        if(!st.empty())return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
      TreeNode * top = st.top();
        st.pop();
        int q = top->val;
        if(top->right)find_left(top->right);
       return q;
    }
    void find_left(TreeNode *root)
    {
        TreeNode * cur = root;
        while(cur)
        {
            st.push(cur);
            cur=cur->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
