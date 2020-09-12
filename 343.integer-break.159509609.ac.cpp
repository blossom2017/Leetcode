class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(dp[j]*(i-j)>dp[i])dp[i]=dp[j]*(i-j);
                if(j*(i-j)>dp[i])dp[i]=j*(i-j);
            }
        }
        return dp[n];
    }
};
