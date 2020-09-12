class Solution {
public:
    void util(vector<vector<int>> &ans,vector<int> temp, int index,vector<int> nums)
    {
       
        if(index==temp.size())
        {
        ans.push_back(temp);    
            return;
        }
        for(int i=index;i<temp.size();i++)
        {
            if(i>index&&temp[i]==temp[index])continue;
        
            swap(temp[index],temp[i]);
          
            util(ans,temp,index+1,nums);
         
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        util(ans,nums,0,nums);
        return ans;
        
        
    }
};
