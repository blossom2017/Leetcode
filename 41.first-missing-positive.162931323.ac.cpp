class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
          int q = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
        {
            swap(A[i],A[q++]);
        }
    }
    int k = q;
    for(int i=0;i<k;i++)
    {
        int  temp=abs(A[i]);
    if(temp<=k)A[temp-1]=-abs(A[temp-1]);        
    
    
    }
    int i;
    for(i=0;i<k;i++)if(A[i]>0)return i+1;
    return i+1;
    
        
    }
};
