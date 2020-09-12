class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> hold(prices.size());
        vector<int> nothold(prices.size());
        hold[0]=-prices[0];
        nothold[0]=0;
        for(int i=1;i<prices.size();i++)
        {
            hold[i]=max(hold[i-1],nothold[i-1]-prices[i]);
            nothold[i]=max(nothold[i-1],hold[i-1]+prices[i]-fee);
        }
      
        return nothold[prices.size()-1];
        
    }
};
