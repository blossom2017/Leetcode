class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b)
    {
        if(a.first!=b.first)return a.first>b.first;
        return a.second<b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),compare);
        vector<pair<int,int>>res;
        for(int i=0;i<people.size();i++)
        {
            res.insert(res.begin()+people[i].second,people[i]);
        }
        return res;
        
    }
};
