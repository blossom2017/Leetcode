class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        vector<int> v(n+1);
        v[0]=1;
        v[1]=10;
       for(int i=2;i<=n;i++)
       {
           int ct = i-1;
           int x =9;
           int y = 9;
           while(ct--)
           {
               x=x*y--;
           }
           v[i]=v[i-1]+x;
          // cout<<v[i]<<" ";
           
       }
            return v[n];
    }
};
