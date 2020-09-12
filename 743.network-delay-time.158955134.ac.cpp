class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        list<pair<int,int>> * adj = new list<pair<int,int>>[N+1];
        vector<int> dist(N+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0];
            int v= times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,K});
        dist[K]=0;
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto it = adj[u].begin();it!=adj[u].end();it++)
            {
                if(dist[(*it).first]>dist[u]+(*it).second)
                {
                    dist[(*it).first]=dist[u]+(*it).second;
                    pq.push({dist[(*it).first],(*it).first});
                }
            }
        }
        int maxt=INT_MIN;
        for(int i=1;i<=N;i++)
        {
            if(dist[i]==INT_MAX)
            {
               // cout<<i<<endl;
                return -1;
            }
            maxt=max(maxt,dist[i]);
        }
       
         return maxt;
        
    }
};
