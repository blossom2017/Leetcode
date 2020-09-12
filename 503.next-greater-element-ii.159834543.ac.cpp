class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i]>=st.top())st.pop();
            if(st.empty())ans[i]=INT_MIN;
            else ans[i]=st.top();
            st.push(nums[i]);
        }
            for(int i=nums.size()-1;i>=0;i--)
        {
           if(ans[i]==INT_MIN)
           {
            while(!st.empty()&&nums[i]>=st.top())st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
           }
          //  st.push(nums[i]);
        }    
        for(int i=0;i<ans.size();i++)if(ans[i]==INT_MIN)ans[i]=-1;
        return ans;
        
    }
};
