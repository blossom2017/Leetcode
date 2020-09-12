class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.length();i++)
        {
            while(!st.empty()&&st.top()>num[i]&&k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            
        }
        while(k--)
            st.pop();
        
        string str;
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        int i=str.length()-1;
       // cout<<str<<endl;
        while(str[i]=='0'&&i>0)
        {
            i--;
            str.pop_back();
        }
     //   cout<<str<<" ";
        reverse(str.begin(),str.end());
        if(str!="")return str;
        else return "0";
    }
};
