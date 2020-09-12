class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //longest common substring approach
        int mxval=0;
        vector<vector<int>> v(A.size()+1,vector<int> (B.size()+1));
        for(int i=0;i<=A.size();i++)
        {
            for(int j=0;j<=B.size();j++)
            {
                if(i==0||j==0)v[i][j]=0;
                else if(A[i-1]==B[j-1])v[i][j]=v[i-1][j-1]+1;
                else v[i][j]=0;
                mxval = max(mxval,v[i][j]);
            }
        }
        return mxval;
        
    }
};
