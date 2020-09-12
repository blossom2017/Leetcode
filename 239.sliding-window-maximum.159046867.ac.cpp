class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int prev;
        vector<int> ans;
        if(nums.size()==0)return ans;
        deque<int> pq;
       for(int i=0;i<k;i++)
       {
           while(!pq.empty()&&nums[i]>=nums[pq.back()])
           {
            //   cout<<"hhhh";
               pq.pop_back();
           }
         //  cout<<"rrrr"<<i<<" ";
           pq.push_back(i);
          // cout<<"pushh"<<nums[pq.front()]<<" ";
        

       }
        ans.push_back(nums[pq.front()]);
        for(int i=k;i<nums.size();i++)
        {
            while(!pq.empty()&&nums[i]>nums[pq.back()])
                pq.pop_back();
            while(!pq.empty()&&pq.front()<=i-k)pq.pop_front();
            pq.push_back(i);
            //cout<<"pushh"<<nums[pq.front()]<<" ";

            ans.push_back(nums[pq.front()]);
        }
        return ans;
    }
};
