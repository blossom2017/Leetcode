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
    TreeNode * util(TreeNode * A)
    {
        if(!A)return NULL;
    if(!A->left&&!A->right)return A;
    TreeNode * leftret = util(A->left);
    TreeNode * rightret =  util(A->right);
    TreeNode * temp = A->right;
  //  A->right=A->left;
   if(leftret)
   {leftret->right = temp;
   A->right = A->left;
    A->left = NULL;
   }
    if(rightret) return rightret;
    else return leftret;
        
    }

    void flatten(TreeNode* A) {
 TreeNode * v = util(A);
    }        
};
