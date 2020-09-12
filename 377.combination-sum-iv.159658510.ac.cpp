class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> ways(target+1);
        ways[0]=1;
        for(int i=0;i<ways.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i>=nums[j])ways[i]+=ways[i-nums[j]];
            }
        }
        return ways[target];
        
        
    }
};
