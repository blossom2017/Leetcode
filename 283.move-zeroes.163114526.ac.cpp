class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int fwd=0;
        while(fwd<nums.size())
        {
            if(nums[fwd]==0)fwd++;
            else 
            {
                swap(nums[fwd],nums[st]);
                fwd++;
                st++;
            }
        }
    }
};
