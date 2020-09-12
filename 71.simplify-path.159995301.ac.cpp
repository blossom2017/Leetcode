class Solution {
public:
    vector<string> split(string str)
    {
        vector<string > ans;
        string temp;
      //  ans.push_back("/");
        int i=1;
        while(i<str.length())
        {
            if(str[i]!='/')temp.push_back(str[i++]);
            else 
            {
               // cout<<"temp"<<" "<<temp<<" rr"<<endl;
                if(temp.compare("")!=0)ans.push_back(temp);
                temp.clear();
                i++;
            }
        }
        if(temp.compare("")!=0)ans.push_back(temp);
        return ans;
    }
    string simplifyPath(string path) {
        vector<string> p = split(path);
        
        stack<string> st;
        for(int i=0;i<p.size();i++)
        {
           // cout<<"here"<<p[i]<<"hh"<<endl;
            if(p[i]==".")continue;
            else if(p[i]==".."&&!st.empty())st.pop();
            else if(p[i]=="..")continue;
            else st.push(p[i]);
        }
        string ans ;
       
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.size()>0)return ans;
        else return "/";
     
    }
};
