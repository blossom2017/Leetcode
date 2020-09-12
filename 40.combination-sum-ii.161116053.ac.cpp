class Solution {
public:
    void util(vector<vector<int>> &ans,vector<int> temp, int index, int sum, int target,vector<int> nums)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(index==nums.size()||sum>target)return;
        for(int i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            util(ans,temp,i+1,sum+nums[i],target,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(ans,temp,0,0,target,candidates);
        for(int i=0;i<ans.size();i++)sort(ans[i].begin(),ans[i].end());
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
        
    }
};
