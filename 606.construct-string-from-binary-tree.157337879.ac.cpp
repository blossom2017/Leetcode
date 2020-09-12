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
  string  util(TreeNode * t)
    {
       
        if(!t)return "";
       
        if(!t->left&&!t->right)return to_string(t->val);
      else if(!t->right)return to_string(t->val)+"("+util(t->left)+")";
      else return to_string(t->val)+"("+util(t->left)+")"+"("+util(t->right)+")";
    }
    string tree2str(TreeNode* t) {
        
        
        return util(t);
        
        
    }
};
