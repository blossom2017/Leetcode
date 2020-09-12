class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> lis(nums.size(),1);
        vector<int> prod(nums.size(),0);
        prod[0]=1;
        int mxval=1,count=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&lis[i]<lis[j]+1)
                {
                   
                    lis[i]=lis[j]+1;
                }
            }
            if(lis[i]==1)prod[i]=1;
            else
            {
            for(int j=0;j<i;j++)
            {
                if(lis[i]==lis[j]+1&&nums[i]>nums[j])prod[i]+=prod[j];
            }
            }
            mxval= max(mxval,lis[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(lis[i]==mxval)
        {
                cout<<"hhhh ";
            count+=prod[i];
            }
        }
        return count;
        
    }
};
