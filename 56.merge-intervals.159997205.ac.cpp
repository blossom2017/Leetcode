/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(struct Interval a, struct Interval b)
{
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        stack<Interval> st;
        std::sort(intervals.begin(),intervals.end(),compare);
       
        for(int i=0;i<intervals.size();i++)
        {
            if(st.empty())st.push(intervals[i]);
            else 
            {
                if(st.top().end>=intervals[i].start)
                {
                    int str = st.top().start;
                    int ed = st.top().end;
                    st.pop();
                    st.push(Interval(str,max(intervals[i].end,ed)));
                }
                else st.push(intervals[i]);                
            }
            
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
