class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size()));
        int tot =0;
        for(int i=0;i<nums.size();i++)tot+=nums[i];
        for(int l=1;l<=nums.size();l++)
        {
           for(int i=0;i<nums.size()-l+1;i++)
           {
               int j=i+l-1;
               if(i==j)dp[i][j]=nums[i];
               else if(j==i+1)dp[i][j]=max(nums[i],nums[j]);
               else dp[i][j]=max( min(dp[i+2][j],dp[i+1][j-1])+nums[i],min(dp[i][j-2],dp[i+1][j-1])+nums[j]);
           }
        }
        int sum1 = dp[0][nums.size()-1];
        int sum2 = tot-sum1;
        if(sum1>=sum2)return true;
        else return false;
        
    }
};
