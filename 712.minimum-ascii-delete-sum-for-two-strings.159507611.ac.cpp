class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
       long long int sum1 =0;
       long long int sum2 =0;
        for(int i=0;i<s1.length();i++)sum1+=s1[i];
        for(int i=0;i<s2.length();i++)sum2+=s2[i];
        vector<vector<pair<int,int>>> v(s1.length()+1,vector<pair<int,int>>(s2.length()+1));
        long long int mxval =0;
        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                if(i==0||j==0)
                {
                    v[i][j]={0,0};
                }
                else if(s1[i-1]==s2[j-1])
                {
                    v[i][j].first = v[i-1][j-1].first+1;
                    v[i][j].second = v[i-1][j-1].second+s1[i-1];
                   if(v[i][j].second>mxval)mxval=v[i][j].second;
                }
                else 
                {
                    if(v[i-1][j].first>v[i][j-1].first)
                    {
                        v[i][j].first = v[i-1][j].first;
                        v[i][j].second = v[i-1][j].second;
                    }
                    else if(v[i][j-1].first>v[i-1][j].first)
                    {
                        v[i][j].first = v[i][j-1].first;
                        v[i][j].second = v[i][j-1].second;
                    }
                    else 
                    {
                        v[i][j].first = v[i][j-1].first;
                        if(v[i-1][j].second> v[i][j-1].second)v[i][j].second = v[i-1][j].second;
                        else v[i][j].second = v[i][j-1].second;
                    }
                }
            }
        }
        return (long long int)(sum1-mxval+sum2-mxval);
    }
};
