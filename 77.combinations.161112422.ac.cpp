class Solution {
public:
    void util(vector<vector<int>>&ans, vector<int> temp,int k, int count,int index,vector<int>nums)
    {
        if(count==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            util(ans,temp,k,count+1,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums(n);
        for(int i=0;i<n;i++)nums[i]=i+1;
        util(ans,temp,k,0,0,nums);
        return ans;
        
    }
};
