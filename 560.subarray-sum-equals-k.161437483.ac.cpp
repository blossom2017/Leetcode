class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> st;
        int sum =0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]==k)count++;
            if(st.find(sum+nums[i]-k)!=st.end())
            {
                count+=st[nums[i]+sum-k];
                
            }
           if(st.find(sum+nums[i])==st.end())st[sum+nums[i]]=1;
            else st[sum+nums[i]]++;
            sum+=nums[i];
            
        }
        
        /*
        O(N2)
        vector<int> sums(nums.size());
        sums[0]=nums[0];
        for(int i=1;i<nums.size();i++)sums[i]=sums[i-1]+nums[i];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sums[i]==k)count++;
            for(int j=0;j<i;j++)
            {
                if(sums[i]-sums[j]==k)count++;
            }
        }
        */
        return count;
        
    }
};
