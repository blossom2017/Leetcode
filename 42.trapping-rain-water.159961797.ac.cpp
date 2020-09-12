class Solution {
public:
    int trap(vector<int>& heights) {
        stack<pair<int,int>> st;
        int val =0;
        for(int i=0;i<heights.size();i++)
        {
         while(!st.empty()&&heights[i]>st.top().first)
         {
             int top = st.top().first;
             
             st.pop();
             if(st.empty())break;
             int ht = min(heights[i],st.top().first)-top;
             val += ht*(i-st.top().second-1);
         }
            st.push({heights[i],i});
        }
        return val;
        
    }
};
