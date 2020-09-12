class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<pair<int,int>,string> m;
        for(int i=0;i<sources.size();i++)
        {
            int n = sources[i].length();
            string str = S.substr(indexes[i],n);
            if(str.compare(sources[i])==0)
            {
                m[{indexes[i],indexes[i]+n-1}]=targets[i];
            }
        }
        int start =0;
        string ans;
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->first.first!=start)
            {
                ans+=(S.substr(start,it->first.first-start));
                start=it->first.first;
            }
            if(it->first.first==start)
            {
                ans+=(it->second);
                start = it->first.second+1;
            }
        }
        if(start!=S.length())ans+=S.substr(start);
        return ans;
        
    }
};
