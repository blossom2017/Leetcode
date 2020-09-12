class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='('||str[i]=='{'||str[i]=='[')st.push(str[i]);
            else 
            {
                if(st.empty())return false;
                char tp = st.top();
                st.pop();
                if(str[i]==')'&&tp!='(')return false;
                if(str[i]=='}'&&tp!='{')return false;
                if(str[i]==']'&&tp!='[')return false;
            }
        }
        if(st.empty())return true;
        else return false;
    }
};
