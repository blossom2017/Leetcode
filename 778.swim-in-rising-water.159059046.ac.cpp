class Solution {
public:
    struct compare
    {
      bool operator()(vector<int> a,vector<int>b)
      {
          return a[0]>b[0];
      }
    };
    int swimInWater(vector<vector<int>>& grid) {
        int startr=0;
        int startc =0;
        int mxtime=INT_MIN;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid.size()));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)visited[i][j]=false;
        }
       int dx[4] ={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        priority_queue<vector<int>,vector<vector<int>>, compare> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;
        int mxval=grid[0][0];
        while(!pq.empty())
        {
            vector<int> front = pq.top();
            pq.pop();
             mxval=front[0];
            if(front[1]==grid.size()-1&&front[2]==grid.size()-1)return front[0];
            for(int i=0;i<4;i++)
            {
                int x= front[1]+dx[i];
                int y = front[2]+dy[i];
                if(x<grid.size()&&x>=0&&y<grid.size()&&y>=0&&!visited[x][y])
                {
                    pq.push({max(grid[x][y],mxval),x,y});
                    visited[x][y]=true;
                }
            }
        }
        return -1;
    }
};
