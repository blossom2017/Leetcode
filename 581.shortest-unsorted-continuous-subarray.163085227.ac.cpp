class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
         if(A.size()<2)return 0;
    int pos =A.size();
    stack<int> st;
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty()&&A[st.top()]>A[i])
        {
            pos = min(pos,st.top());
            st.pop();
        }
        st.push(i);
    }
        cout<<pos<<" ";
    if(pos==A.size())return 0;
        while(!st.empty())st.pop();
    int posr = 0;
    for(int i=A.size()-1;i>=0;i--)
    {
        while(!st.empty()&&A[st.top()]<A[i])
        {
            posr = max(posr,st.top());
            st.pop();
        }
        st.push(i);
    }
    
    return posr-pos+1;
        
    }
};
