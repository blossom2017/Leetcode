class Solution {
public:
    /*
    TLE only for the last testcase
     bool DFS(int i,int j , vector<vector<bool>>  visited,string word,string path,vector<vector<char>>& board)
    {
     //   cout<<"jeee"<<board[i][j]<<" "<<visited[i][j]<<endl;
        visited[i][j]=true;
        path.push_back(board[i][j]);
        if(path.compare(word)==0)return true;
     if(path.length()==word.length())return false;
        vector<pair<int,int>> valid;
        int nextindex=path.length();
        if(i+1<visited.size())valid.push_back({i+1,j});
        if(j+1<visited[0].size())valid.push_back({i,j+1});
        if(i-1>=0)valid.push_back({i-1,j});
        if(j-1>=0)valid.push_back({i,j-1});
        for(int k=0;k<valid.size();k++)
        {
           if(board[valid[k].first][valid[k].second]==word[nextindex])
           {
           if(!visited[valid[k].first][valid[k].second]&& DFS(valid[k].first,valid[k].second,visited,word,path,board))return true;
           }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        vector<bool> found(words.size());
        for(int i=0;i<words.size();i++)found[i]=false;
          vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)visited[i][j]=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                for(int k=0;k<words.size();k++)
                {
                if(board[i][j]==words[k][0]&&!found[k])
                {
                    string path="";
                   bool val=DFS(i,j,visited,words[k],path,board);
                        if(val)
                        {ans.push_back(words[k]);
                         found[k]=true;
                         cout<<found[0]<<" ";
                        }
                }
                        
                        
                    }
                }
            }
        sort(ans.begin(),ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
         return ans;
        }
    */
    struct Trienode
    {
      
        struct Trienode * children[26];
        bool isend;
        string key;
    };
    struct Trienode * getNode()
    {
        struct Trienode * nn = new Trienode;
        for(int i=0;i<26;i++)nn->children[i]=NULL;
        nn->isend = false;
        return nn;
    }
    void insert(struct Trienode * root, string key)
    {
        struct Trienode * ptr = root;
        for(int i=0;i<key.length();i++)
        {
            int index =key[i]-'a';
            if(!ptr->children[index])ptr->children[index]=getNode();
            ptr = ptr->children[index];
            
        }
        ptr->isend = true;
        ptr->key = key;
    }
    void dfs(vector<vector<char>> board, int i, int j, struct Trienode * root,vector<string>& ans)
    {
        if(board[i][j]=='#'||!root->children[board[i][j]-'a'])return;
        root= root->children[board[i][j]-'a'];
        char c = board[i][j];
        if(root->key!="")
        {
           // cout<<"jjjj";
            ans.push_back(root->key);
            root->key="";
            //deduplicate
        }
        board[i][j]='#';
        if(i>0)dfs(board,i-1,j,root,ans);
        if(j>0)dfs(board,i,j-1,root,ans);
        if(i+1<board.size())dfs(board,i+1,j,root,ans);
        if(j+1<board[0].size())dfs(board,i,j+1,root,ans);
        board[i][j]=c;
    }
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct Trienode * root = getNode();
            vector<string> ans;
            for(int i=0;i<words.size();i++)insert(root,words[i]);
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[0].size();j++)
                {
                    dfs(board,i,j,root,ans);
                }
            }
            return ans;
                
        }
    
};
