/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<pair<int , int >,int> m;
        if(points.size()==0)return 0;
        int maxp =1;
        for(int i=0;i<points.size();i++)
        {
            m.clear();
            int duplicate = 0;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[j].x==points[i].x&&points[j].y==points[i].y)
                {
                    duplicate++;
                    
                    continue;
                }
                int dy = points[j].y-points[i].y;
                int dx = points[j].x-points[i].x;
                int gcd = __gcd(dy,dx);
                m[{dy/gcd,dx/gcd}]++;
            }
            maxp=max(maxp,duplicate+1);
            for(auto it = m.begin();it!=m.end();it++)if(it->second+duplicate+1>maxp)maxp=it->second+duplicate+1;
            
        }
        return maxp;
    }
};
