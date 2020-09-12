class Solution {
public:
    struct compare{
      bool operator()(pair<string,int>a, pair<string,int>b)
      {
          if(a.second!=b.second)return a.second<b.second;
          else return a.first>b.first;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq; 
        unordered_map<string,int> m;
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(m.find(words[i])==m.end())m[words[i]]=1;
            else m[words[i]]++;
        }
      for(auto it = m.begin();it!=m.end();it++)pq.push({it->first,it->second});
        for(int ct=0;ct<k;ct++)
        {
            pair<string,int> top = pq.top();
            pq.pop();
            ans.push_back(top.first);
        }
        return ans;
        
    }
};
