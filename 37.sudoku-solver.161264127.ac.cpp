class Solution {
public:
    bool isvalid(int row, int col, vector<vector<char>> temp,int i)
    {
        temp[row][col]='0'+i;
        for(int j=0;j<temp.size();j++)if(temp[row][j]==temp[row][col]&&j!=col)return false;
        for(int j=0;j<temp.size();j++)if(temp[j][col]==temp[row][col]&& j!=row)return false;
         int n = sqrt(temp.size());
        int startr = (row/n)*n;
        int startc = (col/n)*n;
       
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp[i+startr][j+startc]==temp[row][col]&&(i+startr!=row ||j+startc!=col))return false;
            }
        }
      //  cout<<"yyyyy "<<temp[row][col]<<" "<<row<<" "<<col<<endl;
        return true;
    }
    bool filled(vector<vector<char>> temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp.size();j++)if(temp[i][j]=='.')return false;
        }
        return true;
    }
    bool util(vector<vector<char>>&ans,vector<vector<char>> temp,int count,int n)
    {
      // cout<<"lll"<<count;
        if(count==n*n&&filled(temp))
        {
            //cout<<"heee";
          
            ans=temp;
            return true;
        }
        else if(count==n*n)
        {
            //cout<<"bye";
            return false;
        }
        int row =count/n;
        int col = count%n;
      //  cout<<row<<" "<<col<<endl;
        if( temp[row][col]=='.')
           {
        for(int i=1;i<=9;i++)
        {
           if(isvalid(row,col,temp,i))
            {
                temp[row][col]='0'+i;
               if( util(ans,temp,count+1,n))
               {
                   //cout<<"jjjj"<<endl;
                   
                   return true;
               }
                temp[row][col]='.';
            }
        }
          //  cout<<"hereee";
            return false;
           }
        else 
           
        {
            //cout<<"bbb";
            return util(ans,temp,count+1,n);
        }
       
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans;
        bool flag = false;
        util(ans,board,0,board.size());
        board = ans;
        
    }
};
