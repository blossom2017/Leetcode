class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int cz=0;
        int co= 0;
        int sum = 0;
        int maxrange=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==1)sum++;
            else sum--;
            if(sum==0)maxrange=max(maxrange,i+1);
            else
            {
                if(mp.find(sum)!=mp.end())
                   maxrange=max(maxrange,i-mp[sum]);   
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
            else mp[sum]=min(i,mp[sum]);
            
        }
        return maxrange;
        
    }
};
