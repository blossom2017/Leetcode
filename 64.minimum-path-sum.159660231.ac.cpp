class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> sums(grid.size(),vector<int> (grid[0].size()));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0&&j==0)sums[i][j]=grid[i][j];
                else if(i==0)sums[i][j]=sums[i][j-1]+grid[i][j];
                else if(j==0)sums[i][j]=sums[i-1][j]+grid[i][j];
                else sums[i][j]=grid[i][j]+min(sums[i-1][j],sums[i][j-1]);
            }
        }
        return sums[grid.size()-1][grid[0].size()-1];
    }
};
