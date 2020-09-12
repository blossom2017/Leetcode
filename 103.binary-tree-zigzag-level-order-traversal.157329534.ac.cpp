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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int l=1;
    stack<TreeNode * > s1;
        stack<TreeNode *> s2;
        vector<vector<int >> ans;
        if(!root)return ans;
        s1.push(root);
        
        while(!s1.empty()||!s2.empty())
        {
            if(!s1.empty())
            {
               // cout<<"hereeee";
                int size=s1.size();
                vector<int > p;
                while(size--)
                {
                  //  cout<<"geeee";
                    TreeNode * temp= s1.top();
                    p.push_back(temp->val);
                    s1.pop();
                    if(temp->left)s2.push(temp->left);
                    if(temp->right)s2.push(temp->right);
                }
                ans.push_back(p);
            }
            else if(!s2.empty())
            {
                int size= s2.size();
                vector<int > p;
                while(size--)
                {
                    TreeNode * temp= s2.top();
                    p.push_back(temp->val);
                    s2.pop();
                    if(temp->right)s1.push(temp->right);
                    if(temp->left)s1.push(temp->left);
                }
                ans.push_back(p);
            }
        }
     return ans;   
    }
};
