class Solution {
public:
    bool isSubsequence(string s, string t) {
        //memory limit exceeded
        /*
        vector<vector<int>> v(s.length()+1,vector<int> (t.length()+1));
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=t.length();j++)
            {
                if(i==0||j==0)v[i][j]=0;
                else if(s[i-1]==t[j-1])
                {
                    v[i][j]=v[i-1][j-1]+1;
                    if(v[i][j]==s.length())return true;
                }
                else 
                {
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                     if(v[i][j]==s.length())return true;
                    
                    
                }
            }
        }
         return v[s.length()][t.length()]==s.length();
        */
        int i=0;
        int j=0;
        while(i<s.length()&&j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else 
            {
                while(t[j]!=s[i]&&j<t.length())j++;
                if(j==t.length())return false;
                else 
                {
                    i++;
                    j++;
                }
            }
        }
        if(i==s.length()&&j<=t.length())return true;
        else return false;
       
        
    }
};
