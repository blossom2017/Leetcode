class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        q.push({0,0});
        while(!q.empty())
        {
            pair<int,int> front=  q.front();
            q.pop();
            if(front.first+front.second==z)return true;
            if(!s.count({0,front.second}))
            {
            q.push({0,front.second});
            s.insert({0,front.second});
            }
            if(!s.count({front.first,0}))
            {
            q.push({front.first,0});
            s.insert({front.first,0});
            }
            if(!s.count({x,front.second}))
            {
                q.push({x,front.second});
                s.insert({x,front.second});
            }
            if(!s.count({front.first,y}))
               {
                   q.push({front.first,y});
                   s.insert({front.first,y});
               }
            if(!s.count({min(x,front.first+front.second),max(0,front.second-(x-front.first))}))
               {
                   q.push({min(x,front.first+front.second),max(0,front.second-(x-front.first))});
                   s.insert({min(x,front.first+front.second),max(0,front.second-(x-front.first))});
               }
            if(!s.count({max(0,front.first-(y-front.second)),min(y,front.second+front.first)}))
               {
                  q.push({max(0,front.first-(y-front.second)),min(y,front.second+front.first)});
                   s.insert({max(0,front.first-(y-front.second)),min(y,front.second+front.first)});
               }
            
        }
        return false;
        
    }
};
