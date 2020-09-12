class Solution {
public:
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
    bool canFinish(int A, vector<pair<int, int>>& edges) {
        
          list<int> * adj = new list<int> [A+1];
    for(int i=0;i<edges.size();i++)
        adj[edges[i].second].push_back(edges[i].first);
    vector<bool> visited(A+1,false);
    vector<bool> recstack(A+1,false);
    for(int i=1;i<=A;i++)
    if(!visited[i]&&iscycle(i,visited,recstack,adj))return 0;
    return 1;
    }
};
