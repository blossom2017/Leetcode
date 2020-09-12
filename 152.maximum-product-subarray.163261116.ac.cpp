class Solution {
public:
    int maxProduct(vector<int>& A) {
        
        /*
        if(nums.size()==0)return 0;
        int maxsofar =nums[0];
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size()));
        //n^2 is giving TLE error
       
        for(int l=1;l<=nums.size();l++)
        {
            int j ;
            for(int i=0;i<nums.size()-l+1;i++)
            {
                j=i+l-1;
                if(i==j)dp[i][j]=nums[i];
                else if(j==i+1)dp[i][j]=nums[i]*nums[j];
                else 
                {
                    dp[i][j]=dp[i][j-1]*nums[j];
                }
                maxsofar=max(dp[i][j],maxsofar);
            }
        }
        */
        /* solution seen
        if(nums.size()==0)return 0;
       int curmax= nums[0];
        int curmin= nums[0];
        int maxsofar = nums[0];
        for(int i=1;i<nums.size();i++)
        {
         if(nums[i]<0)swap(curmax,curmin);
          curmin=min(nums[i],nums[i]*curmin);
            curmax=max(nums[i]*curmax,nums[i]);
            maxsofar= max(maxsofar,curmax);
        
            
        }
         
        return maxsofar;
        */
        //my own 
        vector<int> maxpos(A.size(),1);
    vector<int> maxneg(A.size(),1);
    if(!A.size())return 0;
    if(A[0]<0)
        maxneg[0]=A[0];

    else maxpos[0]=A[0];
    int mxval =A[0];
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>0)
        {
            maxpos[i]=max(maxpos[i-1]*A[i],A[i]);
            maxneg[i]=maxneg[i-1]*A[i];
        }
        else 
        {
            maxpos[i]=maxneg[i-1]*A[i];
            maxneg[i]=min(maxpos[i-1]*A[i],A[i]);
        }
        mxval = max(mxval,maxpos[i]);
    }
    return mxval;
        
    }
};
