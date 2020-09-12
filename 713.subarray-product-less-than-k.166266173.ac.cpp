class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        /*
        for(int i=0;i<nums.size();i++)
        {
            long long int prod=1;
            for(int j=i;j<nums.size();j++)
            {
                prod*=nums[j];
                if(prod<k)count++;
            }
        }
        return count;
        */
        int start = 0;
        int end=0;
        
        long long int prod=1;
        while(end<nums.size())
        {
            prod*=nums[end];
            while(prod>=k&&start<=end)
                prod/=nums[start++];
            count+=end-start+1;
            end++;
                
            
            
        }
        return count;
        
    }
};
