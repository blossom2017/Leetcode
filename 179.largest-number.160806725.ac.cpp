class Solution {
public:
    static bool compare(int a , int b)
    {
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans;
        for(int i=0;i<nums.size();i++)ans+=to_string(nums[i]);
        int i=ans.length()-1;
        reverse(ans.begin(),ans.end());
        while(ans[i]=='0'&&i!=0)
        
        {
            ans.pop_back();
            i--;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
