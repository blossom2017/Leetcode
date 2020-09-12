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
    TreeNode * util(vector<int> inorder, vector<int> postorder, int lowp,int highp, int lowi, int highi)
    {
        if(lowp>highp||lowi>highi)return NULL;
        TreeNode * nn = new TreeNode (postorder[highp]);
        int i;
        for( i=lowi;i<=highi;i++)if(inorder[i]==postorder[highp])break;
        nn->left =util(inorder,postorder,lowp ,lowp+i-lowi-1 ,lowi,i-1);
        nn->right = util(inorder,postorder,lowp+i-lowi,highp-1,i+1,highi);
        return nn;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return util(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);
        
    }
};
