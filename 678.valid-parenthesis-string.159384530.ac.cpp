class Solution {
public:
    bool checkValidString(string s) {
       
        stack<char> st;
        int used=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]=='*')st.push('*');
            else if(s[i]==')')
            {
                if(st.empty())return false;
                else 
                {
                    int ct=0;
                   while(!st.empty()&&st.top()=='*')
                   {
                       ct++;
                       st.pop();
                       
                   }
                    if(st.empty())
                    {
                        ct--;
                        while(ct>0)
                        {
                            st.push('*');
                            ct--;
                        }
                    }
                    else 
                    {
                        st.pop();
                        
                        while(ct>0)
                        {
                            st.push('*');
                            ct--;
                        }
                    }
                }
            }
        }
        int o=0,un=0;
        stack<char> st2;
        while(!st.empty())
        {
            if(st.top()=='*')
            {
                st2.push('*');
                st.pop();
            }
            else if(st.top()=='(')
            {
               // cout<<"hhhhh";
                if(st2.empty())return false;
                else 
                {
                    st2.pop();
                    st.pop();
                }
            }
        }
        return true;
        
    }
};
