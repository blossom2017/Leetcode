class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        //overflow problems
        while(low<=high)
        {
            int mid = (low+high)>>1;
         //   cout<<mid<<" ";
            if(mid==x/mid)return mid;
            if(mid<x/mid&&(mid+1)>x/(mid+1))return mid;
            if(mid>x/mid)high = mid-1;
            else low=mid+1;
        }
        return 0;
        
    }
};
