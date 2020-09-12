class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0)return 0;
        int mxval =1;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(pairs.size(),1);
        for(int i=1;i<pairs.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1;
            }
            mxval = max(dp[i],mxval);
        }
        return mxval;
        
        
    }
};
