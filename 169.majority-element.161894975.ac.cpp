class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int maj;
        for(int i=0;i<nums.size();i++)
        {
            if(!count)
            {
                maj=nums[i];
                count=1;
            }
            else if(nums[i]==maj)count++;
            else count--;
        }
        return maj;
        
    }
};
