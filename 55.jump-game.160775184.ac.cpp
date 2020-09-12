class Solution {
public:
    bool canJump(vector<int>& A) {
        //O(N)space
        /*
        vector<bool> dp(nums.size());
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
        {
            int st = i+1;
            int end = i+nums[i];
            if(dp[i])
            {
            for(int k=st;k<=end;k++)dp[k]=true;
            }
        }
        return dp[nums.size()-1];
        */
        //O(1)
        int i = 0,n=A.size();
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
    }
};
