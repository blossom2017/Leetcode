class Solution {
public:
   
    bool isInterleave(string A, string B, string C) {
        /*correct
    
       vector<vector<bool>> v(s1.length()+1,vector<bool> (s2.length()+1));
        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                if(i==0&&j==0)v[i][j]=true;
                else if(i==0)v[i][j]=(s2[j-1]==s3[j-1])&&v[i][j-1];
                else if(j==0)v[i][j]=(s1[i-1]==s3[i-1])&&v[i-1][j];
                else if(s3[i+j-1]==s1[i-1]&&s3[i+j-1]!=s2[j-1])v[i][j]=v[i-1][j];
                else if(s3[i+j-1]==s2[j-1]&&s3[i+j-1]!=s1[i-1])v[i][j]=v[i][j-1];
                else if(s3[i+j-1]==s2[j-1]&&s3[i+j-1]==s1[i-1])v[i][j]=v[i][j-1]||v[i-1][j];
                else v[i][j]=false;
            }
        }
        return (v[s1.length()][s2.length()]&&(s1.length()+s2.length()==s3.length()));
        */
          if(C.length()!=A.length()+B.length())return false;
    
    vector<vector<bool>> v(A.length()+1,vector<bool>(B.length()+1));
    for(int i=0;i<=A.length();i++)
    {
        for(int j=0;j<=B.length();j++)
        {
            int index = i+j-1;
            if(i==0&&j==0)v[i][j]=true;
            else if(i==0)v[i][j]=v[i][j-1]&&(C[index]==B[j-1]);
            else if(j==0)v[i][j]=v[i-1][j]&&(C[index]==A[i-1]);
            else if(C[index]==A[i-1]&&C[index]!=B[j-1])v[i][j]=v[i-1][j];
            else if(C[index]==B[j-1]&&C[index]!=A[i-1])v[i][j]=v[i][j-1];
            else if(C[index]==A[i-1])v[i][j]=v[i-1][j]||v[i][j-1];
            else v[i][j]=false;
          //  cout<<v[i][j]<<" ";
            
        }
        //cout<<endl;
    }
    return v[A.length()][B.length()];
    }
};
