class Solution {
public:
    bool isvalid(int i, int count, vector<int> temp)
    {
        temp[count]=i;
        int x=i+1;
        int y = i-1;
        //horizontal attack
        for(int j=count-1;j>=0;j--)
        {
            if(temp[j]==i||temp[j]==x++||temp[j]==y--)return false;
        }
       
        return true;
    }
    vector<string> convert(vector<int> temp,int n)
    {
      //  cout<<"hereee";
        vector<string> v(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)v[i].push_back('.');
        }
        for(int i=0;i<temp.size();i++)
        {
            v[temp[i]][i]='Q';
        }
        return v;
    }
   void util(vector<vector<string>> &ans,vector<int> temp, int count, int n)
    {
      //   cout<<"hereee";
        if(count==n)
        {
            ans.push_back(convert(temp,n));
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isvalid(i,count,temp))
            {
                temp[count]=i;
                util(ans,temp,count+1,n);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> temp(n);
        util(ans,temp,0,n);
        return ans;
        
    }
};
