class Solution {
public:
    int numDecodings(string A) {
        /*
        if(s.length()==0)return 0;
        vector<int> dp (s.length()+1);
        if(s[0]=='0')return 0;
        else dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=s.length();i++)
        {
            if(s[i-1]=='0'&&(s[i-2]!='1'&&s[i-2]!='2'))return 0;
            else if(s[i-1]=='0')dp[i]=dp[i-2];
            else if(s[i-1]!='0'&&s[i-2]=='0')dp[i]=dp[i-2];
            else if(s[i-1]!='0'&&s[i-2]!='0')
            {
                if(stoi(s.substr(i-2,2))<=26)dp[i]=dp[i-1]+dp[i-2];
                else dp[i]=dp[i-1];
            }
        }
          return dp[s.length()];
        */
        vector<int> ways(A.length()+1);
    ways[0]=1;
    if(A[0]=='0')return 0;
    ways[1]=1;
    for(int i=2;i<=A.length();i++)
    {
        if(A[i-1]=='0'&&(A[i-2]>'2'||A[i-2]<='0'))return 0;
        else if(A[i-1]=='0')ways[i]=ways[i-2];
        else if(A[i-1]!='0'&&A[i-2]!='0')
        {
            if(A.substr(i-2,2)>="10"&&A.substr(i-2,2)<="26")ways[i]=ways[i-1]+ways[i-2];
            else ways[i]=ways[i-1];
        }
        else if(A[i-1]!='0'&&A[i-2]=='0')ways[i]=ways[i-1];
    }
    return ways[A.length()];
      
        
    }
};
