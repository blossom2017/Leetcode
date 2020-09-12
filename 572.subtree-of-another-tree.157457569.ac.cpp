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
    void inorder(TreeNode * root, string &str)
{
    if(!root){str.push_back('#');
         return ;
        }
inorder(root->left,str);
    str+=to_string(root->val)+"$";
  inorder(root->right,str);
}
    void preorder(TreeNode * root, string &str)
    {
        if(!root){str.push_back('#');
         return ;
        }
        str+=to_string(root->val)+"$";
       preorder(root->left,str);
preorder(root->right,str);
        
    }
    void postorder(TreeNode * root, string &str)
    {
        if(!root)
        {str.push_back('#');
         return ;
        }
         
postorder(root->left,str);
      postorder(root->right,str);
        str+=to_string(root->val)+"$";
        
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
         string t1,t2,t3,t4,t5,t6;
     inorder(s,t1);
     inorder(t,t2);
        preorder(s,t3);
        preorder(t,t4);
        postorder(s,t5);
        postorder(t,t6);
     cout<<t1<<endl<<t2<<endl;
     return t1.find(t2)!=string::npos&&t3.find(t4)!=string::npos&&t5.find(t6)!=string::npos;
    }
};
