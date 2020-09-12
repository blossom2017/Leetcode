class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<pair<bool,int>>> v(coins.size()+1,vector<pair<bool,int>> (amount+1));
        for(int i=0;i<=coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0&&j==0)
                {
                    v[0][0].first = true;
                    v[0][0].second= 0;
                }
                else if(j==0)
                {
                    v[i][0].first=true;
                    v[i][0].second = 0;
                }
                else if(i==0)
                {
                    v[0][j].first=false;
                    v[0][j].second=0;
                }
                else if(j<coins[i-1])
                {
                    v[i][j].first=v[i-1][j].first;
                    v[i][j].second = v[i-1][j].second;
                }
                else 
                {
                    if(v[i-1][j].first&&v[i][j-coins[i-1]].first)
                    {
                      //  cout<<"heree"<<i<<" "<<j<<v[i-1][j].second<<" "<<1+v[i][j-coins[i-1]].second<<endl;
                        v[i][j].second = min(v[i-1][j].second,1+v[i][j-coins[i-1]].second);
                        v[i][j].first = true;
                    }
                    else if(v[i-1][j].first)
                    {
                        v[i][j].first = v[i-1][j].first;
                        v[i][j].second = v[i-1][j].second;
                    }
                    else 
                    {
                        v[i][j].first = v[i][j-coins[i-1]].first;
                        v[i][j].second = 1+v[i][j-coins[i-1]].second;
                    }
                }
            }
        }
        if(v[coins.size()][amount].first== false )return -1;
        return v[coins.size()][amount].second;
        
        
    }
};
