class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1));
        dp[0][0]=true;
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=p.length();j++)
            {
                dp[i][j]=false;
                if(i==0&&j==0)dp[i][j]=true;
                else if(j==0)dp[i][j]=false;
                else if(i==0&&p[j-1]=='*')dp[i][j]=dp[i][j-1];
                else if(i==0)dp[i][j]=false;
                else if(s[i-1]==p[j-1])dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]|dp[i][j-1];
                   
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
