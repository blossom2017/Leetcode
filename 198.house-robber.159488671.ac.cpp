class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size(),0);
        if(nums.size()==0)return 0;
        else if(nums.size()==1)return nums[0];
        money[0]=nums[0];
     
        money[1]=max(nums[1],money[0]);
        /*
        O(n2)
        int mxval=max(money[0],money[1]);
        for(int i=2;i<nums.size();i++)
        {
            for(int j=0;j<i-1;j++)
            {
                if(money[j]+nums[i]>money[i])money[i]=nums[i]+money[j];
            }
            mxval=max(mxval,money[i]);
        }
        */
        for(int i=2;i<nums.size();i++)
        {
           
            money[i]=max(money[i-1],money[i-2]+nums[i]);
        }
        return money[nums.size()-1];
        
        
    }
};
