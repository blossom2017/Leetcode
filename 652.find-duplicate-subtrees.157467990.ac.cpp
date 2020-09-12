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
    string util(vector<TreeNode *> &ans,TreeNode * root,set<string > &m,set<string> &ansstr)
    {
        string s="";
        if(!root)return s+"#";
        string lstr= util(ans,root->left,m,ansstr);
     
        string rstr= util(ans,root->right,m,ansstr);
   
        s=s+to_string(root->val)+"$"+lstr+rstr;
        if(m.find(s)!=m.end()&&ansstr.find(s)==ansstr.end())
        {
  
            ans.push_back(root);
            ansstr.insert(s);
            return s;
        }
    
        m.insert(s);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> ans;
        set<string>m;
        set<string> ansstr;
        string s=util(ans,root,m,ansstr);
        return ans;
        
    }
};
