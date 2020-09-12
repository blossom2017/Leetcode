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
    void util(TreeNode * root, int hl, int vl,unordered_map<int,pair<int,int >> &m )
    {
        if(!root)return ;
        
        if(m.find(vl)==m.end())m[vl]={hl,hl};
            else 
            {
                m[vl].first=min(m[vl].first,hl);
                m[vl].second=max(m[vl].second,hl);
            }
        if(root->left)util(root->left,2*hl+1,vl+1,m);
        if(root->right)util(root->right,2*hl+2,vl+1,m);
    }
    
  
    int widthOfBinaryTree(TreeNode* root) {
       if(!root)return 0;
       unordered_map<int,pair<int,int >> m ;
        util(root,0,0,m);
        int mx=0;
     
        for(auto it = m.begin();it!=m.end();it++)
        {
          
            if(abs(it->second.second-it->second.first)+1>mx)
            {
                mx= abs(it->second.second-it->second.first)+1;
                
            
            }
        }
      
     return mx;
    }
};
