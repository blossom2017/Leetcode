class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int ret=0;
        while(i<prices.size())
        {
            int j=i+1;
            int f=0;
            while(j<prices.size()&&prices[j]>prices[j-1])
            {
                f=1;
                j++;
            }
            if(f)
            {
                ret+=prices[j-1]-prices[i];
                i=j;
            }
            else i++;
        }
        return ret;
        
    }
};
