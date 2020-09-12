class Solution {
public:
    int findMin(vector<int>& A) {
        int high = A.size()-1;
        int low = 0;
    if(A.size()==1)return A[0];
        int pivot=-1;
         while(low<=high)
    {
        int mid =(low+high)/2;
             if(mid==A.size()-1)
             {
                 if(A[mid]<A[mid-1])
                 {
                 pivot = mid;
                 break;
                 }
             }
             else if(mid==0)
             {
                 if(A[mid]<A[mid+1])
                 {
                 pivot = mid;
                 break;
                 }
             }
      else if(A[mid]<A[mid+1]&&A[mid]<A[mid-1])
        {
            pivot=mid;
            break;
        }
     if(A[mid]>=A[low]&&A[mid]>=A[high])low=mid+1;
        else high=mid-1;
    }
        return A[pivot];
        
    }
};
