class Solution {
public:
    void nextPermutation(vector<int>& A) {
        bool flag = false;
int n = A.size();
    for(int i=A.size()-2;i>=0;i--)
    {
        
           //  cout<<A[i]<<" "<<A[j]<<" ";
            if(A[i]<A[i+1])
            {
              //  cout<<A[i]<<" "<<A[j]<<" ";
              int minval=A[i+1];
              int minindex = i+1;
              for(int k=i+1;k<A.size();k++)
              {
                  if(A[k]>A[i]&&A[k]<minval)
                  {
                      minval=A[k];
                      minindex=k;
                  }
              }
                swap(A[i],A[minindex]);
                sort(A.begin()+i+1,A.end());

                flag =true;
                break;
          
        }
        if(flag)break;
    }
    if(!flag)sort(A.begin(),A.end());
        
    }
};
