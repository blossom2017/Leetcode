class Solution {
public:
    int minCut(string s) {
        cout<<s.length()<<"v";
         int n = s.length();
      /*TLE
       
        int v[n][n];
        
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(i==j)v[i][j]=0;
                else if(j==i+1)
                {
                    if(s[i]==s[j])v[i][j]=0;
                    else v[i][j]=1;
                    
                }
                else 
                {
                if(s[i]==s[j]&&v[i+1][j-1]==0)
                  v[i][j]=v[i+1][j-1];
                    else
                    {
                        v[i][j]=INT_MAX;
                    for(int p = i;p<j;p++)
                    {
                        v[i][j]=min(v[i][j],v[i][p]+v[p+1][j]+1);
                    }
                    }
                }
            }
        }
       */
        vector<int > cuts(n+1);
        for(int i=0;i<=s.length();i++)cuts[i]=i-1;
        for(int i=0;i<=s.length();i++)
        {
            //odd length
            for(int j=0;i-j>=0&&i+j<n&&s[i-j]==s[i+j];j++)
            {
                cuts[i+j+1]=min(cuts[i+j+1],cuts[i-j]+1);
            }
            for(int j=0;i-j+1>=0&&i+j<n&&s[i-j+1]==s[i+j];j++)
            {
                cuts[i+j+1]=min(cuts[i-j+1]+1,cuts[i+j+1]);
            }
        }
        
        return cuts[n];
        
    }
};
