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
    //O(logn )avg space O(N)worst case space considering the recursion stack
    //If we don't consider recursion then it is O(1)
    /*
            void util(TreeNode * root, TreeNode * & prev, vector<TreeNode *> &ans,bool &flag)
{
    if(!root)return;
    util(root->left,prev,ans,flag);
    if(prev&&root->val<prev->val)
    {
       
      if(flag)  
      {
          ans.push_back(prev);
          ans.push_back(root);
          flag=false;
      }
      
       else 
       {
           ans.pop_back();
           ans.push_back(root);
       }
     
    }
    prev=root;
    util(root->right,prev,ans,flag);
}
    void recoverTree(TreeNode* root) {


    vector<TreeNode*> ans;
    TreeNode * prev=NULL;
    bool flag = true;
    util(root,prev,ans,flag);
        if(ans.size()==2)
        {
  int temp = ans[0]->val;
        ans[0]->val=ans[1]->val;
        ans[1]->val=temp;
        
        }
    }
    */
    void recoverTree(TreeNode* root) {
        
        TreeNode * prev = NULL;
        TreeNode * cur = root;
        TreeNode * first = NULL;
        TreeNode * second = NULL;
        while(cur)
        {
            if(prev&&prev->val>=cur->val)
            {
              //  cout<<"hhhh";
                if(!first)first=prev;
                second =cur;
            }
            if(cur->left)
            {
                TreeNode * pred = cur->left;
                while(pred->right&&pred->right!=cur)
                    pred= pred->right;
                if(pred->right==cur)
                {
                    pred->right=NULL;
                    prev=cur;
                    cur=cur->right;
                }
                else 
                {
                    //making a back edge
                    pred->right= cur;
                    cur=cur->left;
                }
                
            }
            else 
            {
                prev = cur;
                cur=cur->right;
            }
        }
        if(first&&second)
        {
           // cout<<"herre";
        int temp =first->val;
            first->val=second->val;
            second->val= temp;
        }
    }
 
};
