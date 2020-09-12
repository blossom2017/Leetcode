class Solution {
public:
    
    double knightProbability(int n, int k, int r, int c) {
        if(k==0)return 1;
    queue<vector<double>> q;
        //row,col,level,
    int row[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
    int col[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int totalstop = 0;
        double rem=0;
        q.push({r,c,0,1});
        //BFS gives memory limits exceeded
        /*
        while(!q.empty())
        {
            //cout<<"hereee";
            vector<double> v = q.front();
            q.pop();
            if(v[2]==k)
            {

                if(v[0]<n&&v[0]>=0&&v[1]<n&&v[1]>=0)rem+=v[3];
                
            }
            else 
            {
                
                    if(v[0]<n&&v[0]>=0&&v[1]<n&&v[1]>=0)
                    {
                      
                    for(int i=0;i<8;i++)
                    {  q.push({v[0]+row[i],v[1]+col[i],v[2]+1,v[3]*0.125});
                       
                    }
                    }
                
                   
               
            }
        }
        
        return rem;
        */
        vector<vector<double>> dp(n,vector<double>(n));
        dp[r][c]=1;
        for(int rounds=0;rounds<k;rounds++)
        {
             vector<vector<double>> dp1(n,vector<double>(n));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int m=0;m<8;m++)
                    {
                        if(i+row[m]<n&&i+row[m]>=0&&j+col[m]<n&&j+col[m]>=0)dp1[i+row[m]][j+col[m]]+=dp[i][j];
                    }
                }
            }
            dp=dp1;
          // fill(dp1.begin(),dp1.end(),0.0);
        }
        cout<<"herer";
        double sum=0;
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)sum+=dp[i][j];
        }
        return sum/pow(8,k);
    
        
    }
};
