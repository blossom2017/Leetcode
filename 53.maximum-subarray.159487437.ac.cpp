class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum (nums.size()+1);
        sum[0]=0;
        int mxval=INT_MIN;
        //O(n2)
        /*
        for(int i=1;i<=nums.size();i++)
        {
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(sum[i]-sum[j]>mxval)mxval = sum[i]-sum[j];
            }
        }
        return mxval;
        */
        int currentmax=nums[0];
        int maxsofar=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            currentmax=max(nums[i]+currentmax,nums[i]);
            maxsofar =max(maxsofar,currentmax);
        }
        return maxsofar;
    }
};
