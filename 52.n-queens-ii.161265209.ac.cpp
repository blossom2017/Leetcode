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
   
   void util(int &ans,vector<int> temp, int count, int n)
    {
      //   cout<<"hereee";
        if(count==n)
        {
            ans++;
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
    int totalNQueens(int n) {
        int ans =0;
        vector<int> temp(n);
        util(ans,temp,0,n);
        return ans;
        
    }
};
