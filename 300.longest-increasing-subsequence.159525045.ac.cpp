class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int mxval=1;
        vector<int> lis(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&lis[i]<lis[j]+1)lis[i]=lis[j]+1;
            }
            mxval=max(lis[i],mxval);
        }
        return mxval;
        
        
    }
};
