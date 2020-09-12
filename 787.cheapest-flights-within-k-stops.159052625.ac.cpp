class Solution {
public:
    struct compare
    {
      bool operator()(vector<int> a, vector<int> b)
      {
          return a[1]>b[1];
      }
    };
    int findCheapestPrice(int n, vector<vector<int>>& times, int src, int dst, int K) {
         list<pair<int,int>> * adj = new list<pair<int,int>>[n+1];
       
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0];
            int v= times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
       priority_queue<vector<int>,vector<vector<int>>,compare> q;
        q.push({src,0,-1});
       
        int val = INT_MAX;
        while(!q.empty())
        {
            vector<int> front = q.top();
            q.pop();
            if(front[0]==dst)
            {
               return front[1];
            }
           if(front[2]+1<=K)
           {
            for(auto it = adj[front[0]].begin();it!=adj[front[0]].end();it++)
            {
             int child=(*it).first;
                int dist= (*it).second;
              
                q.push({child,front[1]+dist,front[2]+1});
            }
           }
            
        }
       if(val!=INT_MAX) return val;
        else return -1;
        
        
    }
};
