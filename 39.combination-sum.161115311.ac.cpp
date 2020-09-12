class Solution {
public:
    void util(vector<vector<int>> &ans,vector<int> temp,int target,int sum,vector<int> nums,int index)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        else if(sum>target||index==nums.size())return;
        for(int i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            util(ans,temp,target,sum+nums[i],nums,i);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(ans,temp,target,0,candidates,0);
        return ans;
        
    }
};
