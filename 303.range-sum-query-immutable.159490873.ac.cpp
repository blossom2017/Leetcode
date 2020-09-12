class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        if(nums.size()>0)sum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
         int   x=nums[i]+sum[i-1];
          sum.push_back(x);
        }
    }
    
    int sumRange(int i, int j) {
        //cout<<sum[2]<<" hhhh";
        if(i==0)return sum[j];
        else return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
