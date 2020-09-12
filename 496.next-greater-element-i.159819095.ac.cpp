class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        map<int,int> mp;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<nums[i])st.pop();
            if(st.empty())mp[nums[i]]=-1;
            else mp[nums[i]]=st.top();
            st.push(nums[i]);
        }
        vector<int> ans(findNums.size());
        for(int i=0;i<findNums.size();i++)
        {
            ans[i]=mp[findNums[i]];
        }
        return ans;
        
    }
};
