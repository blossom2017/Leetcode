class Solution {
public:
    int numTrees(int n) {
        vector<int> bst(n+1);
        bst[0]=1;
        bst[1]=1;
        bst[2]=2;
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                bst[i]+=bst[j-1]*bst[i-j];
            }
        }
        return bst[n];
        
    }
};
