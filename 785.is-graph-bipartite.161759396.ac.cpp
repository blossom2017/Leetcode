class Solution {
public:
    bool valid(vector<vector<int>>& graph,vector<int> &colour,int c ,int u)
    {
        if(colour[u]!=-1)return colour[u]==c;
        colour[u]=c;
        for(int i=0;i<graph[u].size();i++)
        {
            if(!valid(graph,colour,1-c,graph[u][i]))return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(graph.size(),-1);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1&&!valid(graph,colour,0,i))return false;
        }
        return true;
        
    }
};
