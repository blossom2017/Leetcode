class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b)
    {
        if(a.first!=b.first)return a.first<b.first;
        else if(a.first == b.first && a.second<0&&b.second<0)return a.second<b.second;
        else if(a.first == b.first && a.second>0&&b.second>0)return a.second<b.second;
        else if(a.first == b.first && a.second<0)return a.second<b.second;
        else return a.second>b.second;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> coords;
        vector<pair<int,int>> ans;
		for(int i=0;i<buildings.size();i++)
        {
           
			coords.push_back({buildings[i][0], -1*buildings[i][2]});
			coords.push_back({buildings[i][1], buildings[i][2]});
		}
        sort(coords.begin(),coords.end(),compare);
//will sort the points and handle all the edge cases
        map<int,int> m;
        m[0]=1;
        int prevmax = 0;
        //sorted order of keys 
        for(auto it = coords.begin();it!=coords.end();it++)
        {
            
             prevmax = m.rbegin()->first;
            //cout<<"hhh"<<prevmax<<endl;
            
            if((*it).second<0)
            {
                //starting point
                if(m.find(-(*it).second)==m.end())m[-(*it).second]=1;
                else m[-(*it).second]++;
              //  cout<<-(*it).second<<" lll"<<endl;
               
            }
            else 
            {
               
                 m[(*it).second]--;
                //cout<< m[(*it).second]<<" jjj"<<(*it).second<<" ";
                if(m[(*it).second]==0)
                {
                  //  cout<<"herre";
                    m.erase((*it).second);
                }
            }
             int curmax = m.rbegin()->first;
                if(curmax!=prevmax)ans.push_back({(*it).first,curmax});
        }
        return ans;
        
    }
};
