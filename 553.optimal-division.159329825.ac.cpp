class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        int count =0;
        int flag=0;
        if(nums.size()==1)
        {
            ans+=to_string(nums[0]);
            return ans;
        }
        for(int i=0;i<nums.size();i++)
        {
          if(!flag&&i+1!=nums.size()-1&&i!=nums.size()-1)  
          {
              cout<<i<<endl;
              ans+=to_string(nums[i])+"/"+"(";
              flag=1;
          }
            else if(i!=nums.size()-1)ans+=to_string(nums[i])+"/";
            else ans+=to_string(nums[i]);
           
            
        }
        if(flag)
        {
       // ans.pop_back();
        ans.push_back(')');
        }
        return ans;
        
    }
};
