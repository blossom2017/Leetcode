class Solution {
public:
    int maxProfit(vector<int>& A) {
        /*
        O(N2)
        vector<int> dp(prices.size(),-1);
        int mxval=0;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(prices[i]>prices[j]&&dp[i]<prices[i]-prices[j])dp[i]=prices[i]-prices[j];
            }
            mxval=max(mxval,dp[i]);
        }
        return mxval;
        */
         if(A.size()==0)return 0;
    vector<int> mini(A.size());
    vector<int> maxi(A.size());
    mini[0]=A[0];
    
    for(int i=1;i<A.size();i++)mini[i]=min(mini[i-1],A[i]);
    maxi[A.size()-1]=A[A.size()-1];
   int  maxdiff = 0;
    for(int i=A.size()-2;i>=0;i--)
    {
        maxi[i]=max(maxi[i+1],A[i]);
        maxdiff = max(maxi[i]-mini[i],maxdiff);
    }
    return maxdiff;
    }
};
