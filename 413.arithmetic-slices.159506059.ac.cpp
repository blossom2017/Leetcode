class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(),0);
        int sum=0;
        int total =0;
        for(int i=2;i<A.size();i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                int x=1+sum;
                total +=x;
                sum=x;
            }
            else sum =0;
            
           
        }
    return total;
    }
};
