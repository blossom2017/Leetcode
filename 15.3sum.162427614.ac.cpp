class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<nums.size())
        {
            int req = -nums[i];
            int start=i+1;
            int end = nums.size()-1;
            while(start<end)
            {
                if(nums[start]+nums[end]==req)
                {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    int e1=nums[start];
                    int e2=nums[end];
                    while(start<nums.size()&&nums[start]==e1)start++;
                    while(end>=0&&nums[end]==e2)end--;
                }
                else if(nums[start]+nums[end]<req)start++;
                else end--;
            }
                
            while(i+1<nums.size()&&nums[i+1]==nums[i])i++;
            i++;
        }
        return ans;
        
    }
};
