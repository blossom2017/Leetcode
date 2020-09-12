class Solution {
public:
    void util(vector<vector<int>> &ans, vector<int> temp, int index, vector<int> nums)
    {
        ans.push_back(temp);
        if(index==nums.size())return ;
        for(int i=index;i<nums.size();i++)
        {
            if(i&&i>index&&nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            util(ans,temp,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        util(ans,temp,0,nums);
        return ans;
    }
};
