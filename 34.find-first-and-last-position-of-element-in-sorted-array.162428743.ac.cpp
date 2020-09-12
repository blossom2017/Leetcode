class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1,end=-1;
        int low = 0;
        int high = nums.size()-1;
        //first
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                start = mid;
                high=mid-1;
            }
            else if(nums[mid]<target)low=mid+1;
            else high = mid-1;
        }
        //second
        low=0;
        high = nums.size()-1;
       while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                end = mid;
               low=mid+1;
            }
            else if(nums[mid]<target)low=mid+1;
            else high = mid-1;
        }
         return {start,end};
    }
   
};
