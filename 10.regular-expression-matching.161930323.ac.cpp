class Solution {
public:
    bool isMatch(string A, string B) {
        /*
        vector<vector<bool>> v(p.length()+1,vector<bool> (s.length()+1));
        v[0][0]=true;
       for(int i=1;i<=s.length();i++)
           v[0][i]=false;
        for(int i=1;i<=p.length();i++)
            v[i][0]=i>1&&p[i-1]=='*'&&v[i-2][0];
        for(int i=1;i<=p.length();i++)
        {
            for(int j=1;j<=s.length();j++)
            {
                if(p[i-1]!='*')
                {
                    v[i][j]=v[i-1][j-1]&&(p[i-1]=='.'||s[j-1]==p[i-1]);
                }
                else 
                {
                    v[i][j]=v[i-2][j]||((s[j-1]==p[i-2]||p[i-2]=='.')&&v[i][j-1]);
                }
            }
        }
        
        for(int i=0;i<=p.length();i++)
        {
            for(int j=0;j<=s.length();j++)cout<<v[i][j]<<" ";
        cout<<endl;
        }

        return v[p.length()][s.length()];
        */
         vector<vector<bool>> v(B.length()+1,vector<bool>(A.length()+1));
      
    for(int i=0;i<=B.length();i++)
    {
        for(int j=0;j<=A.length();j++)
        {
            if(i==0&&j==0)v[i][j]=true;
            else if(i==0)v[i][j]=false;
            else if(j==0&&B[i-1]=='*'&&i>1)v[i][j]=v[i-2][j];
            else if(j==0)v[i][j]=false;
            else if(A[j-1]==B[i-1])v[i][j]=v[i-1][j-1];
            else if(B[i-1]=='.')v[i][j]=v[i-1][j-1];
            else if(B[i-1]=='*'&&B[i-2]!='.')v[i][j]=(v[i][j-1]&&(A[j-1]==B[i-2]))||v[i-2][j];
            else if(B[i-1]=='*'&&B[i-2]=='.')v[i][j]=v[i][j-1]||v[i-2][j];
            else v[i][j]=false;
        
        }
    }
    return v[B.length()][A.length()];
       
        
        
    }
};
