class Solution {
public:
    //very inefficient solution wrt time
    void util(vector<vector<int>> &ans,vector<int> temp, int index,vector<int> nums,int target)
    {
       
        if(index==target||nums.size()==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            vector<int> t;
            t=nums;
            t.erase(t.begin()+i);
            util(ans,temp,index+1,t,target);
        
            temp.pop_back();
        }
    }
    void util2(vector<vector<int>> &ans, vector<int> &temp,int index)
    {
        if(index>=temp.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<temp.size();i++)
        {
            swap(temp[index],temp[i]);
            util2(ans,temp,index+1);
            swap(temp[index],temp[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        util2(ans,nums,0);
        return ans;
        
    }
};
