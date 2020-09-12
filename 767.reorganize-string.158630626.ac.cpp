class Solution {
public:
    struct comp
    {
        bool operator()(pair<char,int>a,pair<char,int> b)
        {
            return a.second<b.second;
        }
    };
    string reorganizeString(string S) {
        map<char,int>m;
        for(int i=0;i<S.length();i++)
        {
            if(m.find(S[i])==m.end())m[S[i]]=1;
           else m[S[i]]++;
            if(S.length()%2==0&&m[S[i]]>=S.length()/2+1)return "";
            else if(m[S[i]]>S.length()/2+1)return "";
        }
priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;        
      for(auto it = m.begin();it!=m.end();it++)
      {
          pq.push({it->first,it->second});
          cout<<it->first<<" "<<it->second<<endl;
      }
        string ans;
        char prev='$';
        int freq=-1;
        while(pq.size()!=0)
        {
            pair<char,int> top= pq.top();
           
            pq.pop();
            ans.push_back(top.first);
            
         //   cout<<freq<<" "<<top.first<<endl;
            if(freq>0&&prev!='$')pq.push({prev,freq});
            prev=top.first;
              freq= top.second-1;
            
        }
        
        return ans;
        
    }
};
