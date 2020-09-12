class Solution {
public:
    struct compare
    {
        bool operator()(pair<char,int> a, pair<char,int> b)
        {
            return a.second<b.second;
        }
    };
    string frequencySort(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])==m.end())m[s[i]]=1;
            else m[s[i]]++;
            
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        for(auto it = m.begin();it!=m.end();it++)
        {
            pq.push({it->first,it->second});
        }
        string ans;
        while(!pq.empty())
        {
            pair<char,int> top=pq.top();
            pq.pop();
            for(int i=0;i<top.second;i++)ans.push_back(top.first);
            
        }
        return ans;
        
        
    }
};
