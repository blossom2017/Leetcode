class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        if(grid[0][0]==1||grid[grid.size()-1][grid[0].size()-1]==1)return 0;
        vector<vector<int>> v(grid.size(),vector<int> (grid[0].size()));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0&&j==0&&grid[i][j]==0)v[i][j]=1;
                else if(i==0&&j==0)v[i][j]=0;
                else if(i==0&&grid[i][j-1]==0)v[i][j]=v[i][j-1];
                else if(j==0&&grid[i-1][j]==0)v[i][j]=v[i-1][j];
                else if(i==0||j==0)v[i][j]=0;
                else 
                {
                    if(grid[i-1][j]==0)v[i][j]=v[i-1][j];
                    if(grid[i][j-1]==0)v[i][j]+=v[i][j-1];
                }
                
            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)cout<<v[i][j]<<" ";
            cout<<endl;
        }
        
        return v[grid.size()-1][grid[0].size()-1];
        
    }
};
