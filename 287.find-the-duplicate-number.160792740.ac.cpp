class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //After modifying the array 
        /*
        for(int i=0;i<nums.size();i++)
        {
            int absval = abs(nums[i]);
            int index = absval-1;
            if(nums[index]<0)return index+1;
            else nums[index]=-nums[index];
        }*/
        //without modification
        if(nums.size()==0)return -1;
        int slow =nums[0];
        int fast = nums[nums[0]];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        }
        fast =0;
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
      
        
    }
};
