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

    vector<string> split(string str)
    {
        vector<string> ans;
        int i=0;
        string temp;
        while(i<str.length())
        {
            if(str[i]!='$')temp.push_back(str[i++]);
            else 
            {
                ans.push_back(temp);
                i++;
                temp.clear();
            }
        }
        return ans;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode * > q;
        q.push(root);
        string res;
        while(!q.empty())
        {
            struct TreeNode * f = q.front();
            q.pop();
            if(!f)res+="#$";
            else res+=to_string(f->val)+"$";
            if(f)
            {
                q.push(f->left);
                q.push(f->right);
            }
        }
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        vector<string> values = split(data);
        TreeNode * root = new TreeNode(stoi(values[0]));
       cout<<values.size()<<" ";
        queue<TreeNode *> q;
        q.push(root);
        int i=1;
        while(i<values.size())
            
        {
            cout<<values[i]<<" ";
            TreeNode * par =q.front();
            q.pop();
            
            if(values[i]!="#")
                
            {
                par->left = new TreeNode (stoi(values[i]));
                q.push(par->left);
            }
                else par->left = NULL;
              i++;
            
                
                
            if(values[i]!="#")
            {
                par->right = new TreeNode (stoi(values[i]));
                q.push(par->right);
            } 
            else par->right = NULL;
                
            i++;
            }
           
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
