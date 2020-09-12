class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        map<char,int> o;
        for(int i=0;i<t.length();i++)
        {
            if(o.find(t[i])==o.end())o[t[i]]=1;
            else o[t[i]]++;
        }
        int start =0;
        int i=0;
        int minw = INT_MAX;
        string subs;
        int count = 0;
        while(i<s.length())
        {
           // cout<<"hereee"<<i;
            if(m.find(s[i])==m.end())m[s[i]]=1;
            else m[s[i]]++;
            if(o.find(s[i])!=o.end()&&m[s[i]]==o[s[i]])count++;
            
             
            if(count>=o.size())
            {
                while(m.size()>=o.size())
                {
                    if(o.find(s[start])==o.end())
                    {
                       //cout<<"jjj";
                        m[s[start]]--;
                        if(m[s[start]]==0)m.erase(s[start]);
                        start++;
                    }
                    else 
                    {
                        if(m[s[start]]>o[s[start]])
                        {
                          // cout<<"yyy";
                            m[s[start]]--;
                             if(m[s[start]]==0)m.erase(s[start]);
                             start++;
                            
                        }
                        else break;
                    }
                }
                if(i-start+1<minw)
                {
                    minw= i-start+1;
                    subs = s.substr(start,minw);
                }
            }
            i++;
        }
        return subs;
    }
};
