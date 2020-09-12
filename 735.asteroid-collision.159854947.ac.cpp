class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int i=0;
        while(i<ast.size())
        {
            if(ast[i]>0)st.push(ast[i++]);
            else if(ast[i]<0)
            {
                if(st.empty()||st.top()<0)
                {
                   
                    st.push(ast[i++]);
                    continue;
                }
                else 
                {
                    int tp = st.top();
                    st.pop();
                    int ne= tp+ast[i];
                 if(ne==0)
                 {
                     i++;
                     continue;
                 }
                    else 
                    {
                        if(ne>0)
                        {
                            st.push(tp);
                            i++;
                        }
                       
                        
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
