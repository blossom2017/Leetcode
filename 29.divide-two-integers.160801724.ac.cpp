class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
        int sign;
        if((divisor<0)^(dividend<0))sign = -1;
        else sign=1;
        long long int dvs= labs(divisor);
        long long int dvd = labs(dividend);
        int res =0;
        while(dvd>=dvs)
        {
            long long int temp = dvs,multiple =1;
            while(dvd>=(temp<<1))
            {
                temp=temp<<1;
                multiple=multiple<<1;
                
            }
            res+=multiple;
            dvd-=temp;
        }
        return res*sign;
        
    }
};
