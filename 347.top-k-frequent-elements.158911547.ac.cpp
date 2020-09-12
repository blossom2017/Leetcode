class Solution {
public:
    struct compare{
      bool operator()(pair<int,int> a, pair<int,int> b)
      {
          return a.second<b.second;
      }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())m[nums[i]]=1;
            else m[nums[i]]++;
            
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto it = m.begin();it!=m.end();it++)pq.push({it->first,it->second});
        for(int ct=0;ct<k;ct++)
        {
            pair<int,int> top=pq.top();
            pq.pop();
            ans.push_back(top.first);
        }
        return ans;
        
    }
};
