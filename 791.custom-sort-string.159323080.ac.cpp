class Solution {
public:
    struct compare
    {
      bool operator()(pair<int,char> a,pair<int,char> b)
      {
          //maxheap
          return a.first<b.first;
      }
    };
    string customSortString(string S, string T) {
    priority_queue<pair<int,char>,vector<pair<int,char>>,compare> pq;
        map<char,int> mp;
        for(int i=0;i<S.length();i++)
        {
            mp[S[i]]=S.length()-1-i;
        }
        for(int i=0;i<T.length();i++)
        {
         if(mp.find(T[i])!=mp.end())   pq.push({mp[T[i]],T[i]});
            else pq.push({-1,T[i]});
        }
        string ans;
        while(!pq.empty())
        {
            char front = pq.top().second;
            pq.pop();
            ans.push_back(front);
        }
        return ans;
        
    }
};
