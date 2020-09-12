class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        if(row!=col)return false;
        int d= sqrt(row);
        
        for(int i=0;i<row;i++)
        {
            set<char> str;
            set<char> stc;
            for(int j=0;j<col;j++)
            {
                if(board[i][j]!='.'&&stc.count(board[i][j]))return false;
               if(board[i][j]!='.') stc.insert(board[i][j]);
            }
            for(int j=0;j<col;j++)
            {
               if(board[j][i]!='.'&&str.count(board[j][i]))return false;
                if(board[j][i]!='.')str.insert(board[j][i]);
            }
        }
        for(int i=0;i<col;i+=d)
        {
            for(int j=0;j<col;j+=d)
            {
                set<char> st;
                for(int k=0;k<d;k++)
                {
                    for(int l=0;l<d;l++)
                    {
                        if(board[i+k][j+l]!='.'&&st.count(board[i+k][j+l]))return false;
                        st.insert(board[i+k][j+l]);
                    }
                }
            }
        }
        return true;
        
    }
};
