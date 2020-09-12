class Solution {
public:
    vector<int> countBits(int num) {
        vector<int > dp(num+1);
        if(num==0)return {0};
        else if(num==1)return {0,1};
        else if(num==2)return {0,1,1};
        else if(num==3)return {0,1,1,2};
        dp[0]=0;
        dp[1]=1;
        dp[2]=dp[1];
        dp[3]=2;
        int near =0;
        for(int i=4;i<=num;i++)
        {
            if((i&(i-1))==0)near=i;
            dp[i]=1+dp[i-near];
        }
        return dp;
        
    }
};
