class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int absval = abs(nums[i]);
            int index = absval-1;
            if(nums[index]>0)nums[index]=-nums[index];
            else 
            {
                ans.push_back(index+1);
                nums[index]=-nums[index];
            }
        }
        return ans;
    }
};
