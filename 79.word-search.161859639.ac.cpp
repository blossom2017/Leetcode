class Solution {
public:
    /*
    was able to pass but not efficient
    
    bool DFS(int i,int j ,string word,string path,vector<vector<char>>& board)
    {
     //   cout<<"jeee"<<board[i][j]<<" "<<visited[i][j]<<endl;
     //   visited[i][j]=true;
        board[i][j]='#';
        path.push_back(board[i][j]);
        if(path.compare(word)==0)return true;
     if(path.length()==word.length())return false;
        vector<pair<int,int>> valid;
        int nextindex=path.length();
        if(i+1<board.size())valid.push_back({i+1,j});
        if(j+1<board[0].size())valid.push_back({i,j+1});
        if(i-1>=0)valid.push_back({i-1,j});
        if(j-1>=0)valid.push_back({i,j-1});
        for(int k=0;k<valid.size();k++)
        {
           if(board[valid[k].first][valid[k].second]==word[nextindex])
           {
           if( DFS(valid[k].first,valid[k].second,word,path,board))return true;
           }
        }
        return false;
    }
    */
    bool dfs(vector<vector<char>> A,string path,string B,int i,int j,int index)
{
      
    if(A[i][j]==B[index])  path.push_back(A[i][j]);
    else return false;
        char c = A[i][j];
        A[i][j]='#';
    if(path==B)return true;
    if(path.length()>=B.length())return false;
  
    if(i+1<A.size()&&dfs(A,path,B,i+1,j,index+1))return true;
    if(i-1>=0&&dfs(A,path,B,i-1,j,index+1))return true;
     if(j-1>=0&&dfs(A,path,B,i,j-1,index+1))return true;
     if(j+1<A[0].size()&&dfs(A,path,B,i,j+1,index+1))return true;
A[i][j]=c;
    return false;
}
    
    
    bool exist(vector<vector<char>>& board, string word) {
  
       
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    string path="";
                   bool val=dfs(board,"",word,i,j,0);
                        if(val)return true;
                        
                        
                    }
                }
            }
         return false;
        }
       
        
    
};
