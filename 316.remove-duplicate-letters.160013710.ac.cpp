class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<vector<int>>mp(26,vector<int>());
        for(int i=0;i<s.length();i++)mp[s[i]-'a'].push_back(i);
        vector<bool> visited(26,false);
        for(int i=0;i<s.length();i++)
        {
            if(!visited[s[i]-'a'])
            {
            while(!st.empty()&&st.top()>=s[i])
            {
                if(st.top()==s[i])st.pop();
                else 
                {
                    bool flag = false;
                    for(int pos= mp[st.top()-'a'].size()-1;pos>=0;pos--)if(mp[st.top()-'a'][pos]>=i)
                    {
                        flag=true;
                        visited[st.top()-'a']=false;
                        st.pop();
                        break;
                    }
                    if(!flag)break;
                }
            }
            }
            if(!visited[s[i]-'a'])
            {
            st.push(s[i]);
                visited[s[i]-'a']=true;
            }
            
        }
        string ans;
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
        
    }
};
