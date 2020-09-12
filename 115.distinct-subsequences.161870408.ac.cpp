class Solution {
public:
    int numDistinct(string A, string B) {
        /*Best
        vector<vector<int>> v(s.length()+1,vector<int>(t.length()+1));
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=t.length();j++)
            {
                if(i==0&&j==0)v[i][j]=1;
                else if(j==0)v[i][j]=1;
                else if(i==0)v[i][j]=0;
                else if(s[i-1]==t[j-1])v[i][j]=v[i-1][j]+v[i-1][j-1];
                else v[i][j]=v[i-1][j];
            }
        }
        return v[s.length()][t.length()];
        */
          vector<vector<int>> v(A.length()+1,vector<int> (B.length()+1));
    vector<vector<int>> ways(A.length()+1,vector<int> (B.length()+1));
    for(int i=0;i<=A.length();i++)
    {
        for(int j=0;j<=B.length();j++)
        {
            if(i==0||j==0)
            {
                v[i][j]=0;
                ways[i][j]=1;
            }
            else if(A[i-1]==B[j-1])
            {
                v[i][j]=v[i-1][j-1]+1;
                ways[i][j]=ways[i-1][j-1];
                if(v[i][j]==v[i-1][j])ways[i][j]+=ways[i-1][j];
                
            }
            else 
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
                if(v[i][j]==v[i-1][j])ways[i][j]=ways[i-1][j];
                else ways[i][j]=ways[i][j-1];
                
            }
           // cout<<ways[i][j]<<" ";
            
        }
    //    cout<<endl;
    }
    int total=ways[A.length()][B.length()];
 
   if(v[A.length()][B.length()]==B.length())
    return total;
    else return 0;
    }
};
