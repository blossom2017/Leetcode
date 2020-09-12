class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')st.push(s[i]);
            else if(s[i]=='[')st.push(s[i]);
            else if(s[i]==']')
            {
                string temp;
                while(!st.empty()&&st.top()!='[')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                //open braces
                st.pop();
                reverse(temp.begin(),temp.end());
              string numstr;
                while(!st.empty()&&st.top()>='0'&&st.top()<='9')
                {
                    numstr.push_back(st.top());
                    st.pop();
                    
                }
                reverse(numstr.begin(),numstr.end());
                string ans;
                for(int k=0;k<stoi(numstr);k++)
                {
                    ans+=temp;
                }
                
                for(int k=0;k<ans.length();k++)
                {
                    st.push(ans[k]);
                }
            }
            else st.push(s[i]);
        }
        string res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
