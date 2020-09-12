class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
       bool dp[100][100][100]={false};
        int len = s1.length();
        for(int i=len-1;i>=0;i--)
        {
            for(int j=len-1;j>=0;j--)
            {
           dp[i][j][1]=(s1[i]==s2[j]);
                for(int l=2;i+l-1<len && j+l-1<len;l++)
                {
                    for(int n=1;n<l;n++)
                    {
                        dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
                        dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
                    }
                }
            }
        }
        return dp[0][0][len];
        /*
        int len=s1.size();
        bool dp[100][100][100]={false};
        for (int i=len-1;i>=0;i--)
            for (int j=len-1;j>=0;j--) {
                dp[i][j][1]=(s1[i]==s2[j]);
                for (int l=2;i+l<=len && j+l<=len;l++) {
                    for (int n=1;n<l;n++) {
                        dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
                        dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
                    }
                }
            }
        return dp[0][0][len-1];
        */
        
        
    }
};
