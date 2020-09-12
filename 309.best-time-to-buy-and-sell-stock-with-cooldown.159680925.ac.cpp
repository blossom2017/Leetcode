class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold(prices.size());
        if(prices.size()==0)return 0;
        vector<int> nothold(prices.size());
        hold[0]=-prices[0];
        nothold[0]=0;
        int flag = 1;
        for(int i=1;i<prices.size();i++)
        {
               if(i-2>=0&&nothold[i-1]==nothold[i-2])
                hold[i]=max(nothold[i-1]-prices[i],hold[i-1]);
               else hold[i]=max(hold[i-1],nothold[i-2]-prices[i]);
                nothold[i]=max(hold[i-1]+prices[i],nothold[i-1]);
               
        }
        //for(int i=0;i<prices.size();i++)cout<<hold[i]<<" "<<nothold[i]<<endl;
        return nothold[prices.size()-1];
        
    }
};
