class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
         if(A.size()==0)return 0;
    int minp = INT_MAX;
    vector<vector<int>> sum(A.size(),vector<int> (A[0].size()));
    int n = A.size()-1;
    int m = A[0].size()-1;
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n&&j==m)sum[i][j]=max(1,1-A[i][j]);
            else if(i==n)sum[i][j]=max(-A[i][j]+sum[i][j+1],1);
            else if(j==m)sum[i][j]=max(-A[i][j]+sum[i+1][j],1);
            else sum[i][j]=max(1,-A[i][j]+min(sum[i+1][j],sum[i][j+1]));
       
        }
    }
   
return sum[0][0];
        
    }
};
