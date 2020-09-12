class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*most optimal solution
        if(heights.size()==0)return 0;
        int mxarea =0;
        heights.push_back(0);
        stack<int> st;
        for(int j=0;j<heights.size();j++)
        {
            if(st.empty()||heights[j]>heights[st.top()])st.push(j);
            else 
            {
                while(!st.empty()&&heights[j]<=heights[st.top()])
                {
                    int tp = st.top();
                    st.pop();
                    int width;
                    if(st.empty())width = -1;
                    else width = st.top();
                    int area = heights[tp]*(j-1-width);
                    mxarea = max(mxarea,area);
                }
                st.push(j);
            }
        }
        return mxarea;
        */
        vector<int> nextright(heights.size());
        vector<int> nextleft(heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())nextleft[i]=-1;
            else 
            {
                while(!st.empty()&&heights[st.top()]>=heights[i])st.pop();
                if(st.empty())nextleft[i]=-1;
                else nextleft[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(st.empty())nextright[i]=heights.size();
            else 
            {
                while(!st.empty()&&heights[st.top()]>=heights[i])st.pop();
                if(st.empty())nextright[i]=heights.size();
                else nextright[i]=st.top();
            }
            st.push(i);
        }
        int mxarea = 0;
        for(int i=0;i<heights.size();i++)mxarea=max(mxarea,heights[i]*(nextright[i]-nextleft[i]-1));
        return mxarea;
        
        
    }
};
