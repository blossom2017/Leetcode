class Solution {
public:
    vector<string > split(string str)
    {
        vector<string>ans;
        int i=0;
        string temp;
        while(i<str.length())
        {
            if(str[i]!=':')
                temp.push_back(str[i++]);
            else 
            {
                ans.push_back(temp);
                temp.clear();
                i++;
            }
            
            
        }
        ans.push_back(temp);
        return ans;
    }
    /*
    int idx = Integer.valueOf(s[0]);
        int t = Integer.valueOf(s[2]);
        
        if(s[1].equals("start")) {
            stack.push(new int[]{idx, t});
        } else {
            int v = t-stack.pop()[1]+1;
            res[idx] += v;
            if(!stack.empty()) res[stack.peek()[0]] -= v;
        }
    }
    */
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>> st;
        vector<int> ans(n);
        for(int i=0;i<logs.size();i++)
        {
            
            int index= logs[i].find(':');
              vector<string> b= split(logs[i]);
            if(b[1].compare("start")==0)
            {
                st.push({stoi(b[0]),stoi(b[2])});
                
            }
            else 
            {
                
                int v = stoi(b[2])-st.top().second+1;
                st.pop();
                ans[stoi(b[0])]+=v;
                if(!st.empty())ans[st.top().first]-=v;
            }
           
        }
        return ans;
        
    }
};
