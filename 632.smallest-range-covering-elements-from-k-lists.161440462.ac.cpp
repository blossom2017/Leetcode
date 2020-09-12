class Solution {
public:
    struct compare
    {
      bool operator()(vector<int> a,vector<int> b)
      {
          return a[0]>b[0];
      }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>, compare> pq;
        int maxn =INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],i,0});
            maxn =max(maxn,nums[i][0]);
        }
        int range = INT_MAX;
        int start =-1;
        int end = -1;
        while(pq.size()==nums.size())
        {
            vector<int> front = pq.top();
            pq.pop();
            int min= front[0];
            if(maxn-min<range)
            {
                start = min;
                end = maxn;
                range = maxn-min;
            }
            int index= front[1];
            if(front[2]+1<nums[index].size())
            {
                maxn = max(maxn,nums[index][front[2]+1]);
                pq.push({nums[index][front[2]+1],index,front[2]+1});
            }
            else break;
        }
        return {start,end};
        
    }
};
