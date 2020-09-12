class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int mxval=1;
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>> v(s.length()+1,vector<int> (s.length()+1));
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=s.length();j++)
            {
                if(i==0||j==0)v[i][j]=0;
                else if(s[i-1]==rev[j-1])v[i][j]=v[i-1][j-1]+1;
                else v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
        return v[s.length()][s.length()];
        
    }
};
