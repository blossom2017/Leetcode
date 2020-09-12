/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode * root,string &s)
    {
        if(!root)return;
        s+=to_string(root->val)+"$";
        if(root->left)preorder(root->left,s);
        if(root->right)preorder(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       // cout<<data<<" ffff";
        vector<int> num;
        int i=0;
        string temp;
        while(i<data.length())
        {
          //  cout<<temp<<" hhhh";
            if(data[i]!='$')temp.push_back(data[i++]);
            else 
            {
                cout<<temp<<" ";
                if(temp.compare("")!=0)num.push_back(stoi(temp));
                temp.clear();
                i++;
            }
        }
        if(num.size()==0)return NULL;
        stack<TreeNode *> st;
        TreeNode * root = new TreeNode(num[0]);
        st.push(root);
        for(int i=1;i<num.size();i++)
        {
            TreeNode * temp =NULL;
            int tempval;
            while(!st.empty()&&num[i]>st.top()->val)
            {
                temp = st.top();
                st.pop();
            }
            if(temp)
            {temp->right = new TreeNode(num[i]);
            st.push(temp->right);
            }
            else 
            {
                st.top()->left = new TreeNode(num[i]);
                st.push(st.top()->left);
            }
            
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
