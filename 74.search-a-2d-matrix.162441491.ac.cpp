class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
      //  correct
        int row=matrix.size();
        if(matrix.size()==0)return false;
        int cnum = matrix[0].size();
        int high = row*cnum-1;
        int low = 0;
        while(low<=high)
        {
            
            int mid = (low+high)>>1;
            int r,c;
            if(cnum==0)r=mid;
            else r =mid/cnum;
            if(cnum==0)c=0;
            else c= mid%cnum;
    //        cout<<low<<" "<<high<<" "<<r<<" "<<c<<endl;
            if(matrix[r][c]==target)
                return true;
            if(matrix[r][c]>target)high = mid-1;
            else low=mid+1;
        }
        return false;
        
    
    }
};
