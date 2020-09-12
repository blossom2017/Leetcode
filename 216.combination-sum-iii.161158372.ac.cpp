class Solution {
public:
    void util(vector<vector<int>> &ans,vector<int> temp,int sum,int target,int k,int index,vector<int> nums)
    {
        if(temp.size()==k)
        {
            if(sum==target)
            {
                cout<<"h";
                ans.push_back(temp);
            }
            return;
        }
        if(temp.size()>k||(index==nums.size())||sum>target)return;
        for(int i= index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            util(ans,temp,sum+nums[i],target,k,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for(int i=0;i<9;i++)nums[i]=i+1;
        vector<vector<int>> ans;
        vector<int> temp;
        util(ans,temp,0,n,k,0,nums);
        return ans;
    }
};
