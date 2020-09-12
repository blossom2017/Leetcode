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
     TreeNode * util(vector<int> &preorder,vector<int> &inorder, int lowpre, int highpre,int lowi,int highi)
 {
     if(lowi>highi||lowpre>highpre)return NULL;
     TreeNode * nn = new TreeNode (preorder[lowpre]);
     int i;
     for(i=lowi;i<=highi;i++)if(inorder[i]==preorder[lowpre])break;
     int sleft = i-lowi;
     int sright = highi-i;
     nn->left = util(preorder,inorder,lowpre+1,lowpre+1+sleft-1 ,lowi,i-1);
     nn->right = util(preorder,inorder,lowpre+1+sleft, highpre,i+1,highi);
     return nn;
     
 }
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    return util(A,B,0,A.size()-1,0,B.size()-1);
    
}
};
