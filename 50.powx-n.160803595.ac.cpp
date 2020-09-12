class Solution {
public:
    double myPow(double x, int n) {
      // cout<<x<<" "<<n<<endl;
        if(n==0)return 1;
     if(n<0)
        {
         //cout<<"jjjj"<<-n<<" ";  
         if(n==INT_MIN&&x<0)
         {
             x=-1/x;
         }
         else x=1/x;
         n=(n!=INT_MIN)?-n:INT_MAX;
       
        }
     if(n%2==0)return myPow(x*x,n/2);
        else return x*myPow(x*x,n/2);
        
    }
};
