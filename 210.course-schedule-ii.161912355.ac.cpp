class Solution {
public:
    void dfs(int i, vector<bool>&visited,vector<int> &time,int &t,list<int>* adj)
    {
        visited[i]=true;
        for(auto it = adj[i].begin();it!=adj[i].end();it++)if(!visited[*it])dfs(*it,visited,time,t,adj);
        time[i]=t++;
    }
       bool iscycle(int u, vector<bool> &visited,vector<bool> &recstack,list<int> *adj)
{
    
    visited[u]=true;
    recstack[u]=true;
    for(auto it = adj[u].begin();it!=adj[u].end();it++)
    {
        if(!visited[*it]&&iscycle(*it,visited,recstack,adj))return true;
        if(recstack[*it])return true;
    }
    recstack[u]=false;
    return false;
}
  static  bool compare(pair<int,int>a, pair<int,int> b)
    {
        return a.first<b.first;
    }
    vector<int> findOrder(int num, vector<pair<int, int>>& edges) {
        list<int> * adj = new list<int> [num];
        for(int i=0;i<edges.size();i++)
        {
            int child=edges[i].second;
            int parent = edges[i].first;
            adj[parent].push_back(child);
        }
        vector<int> time(num);
        vector<bool> visited(num,false);
        vector<bool> recstack(num,false);
        int t;
        for(int i=0;i<num;i++)
        {
        
            if(!visited[i]&&iscycle(i,visited,recstack,adj))return {};
            
        }
        for(int i=0;i<num;i++)visited[i]=false;
         t =0; 
        for(int i=0;i<num;i++)
        {
        
            
            if(!visited[i])dfs(i,visited,time,t,adj);
        }
   //     cout<<time[0]<<" "<<time[1]<<" ";
        vector<pair<int,int>> v(num);
        for(int i=0;i<time.size();i++)
        {
            v[i].first=time[i];
            v[i].second = i;
        }
        sort(v.begin(),v.end(),compare);
        vector<int> ans( num);
        for(int i=0;i<num;i++)ans[i]=v[i].second;
        return ans;
            
        
        
    }
};
