class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]);
        int ele;
        for(int ct=0;ct<k;ct++)
        {
             ele= pq.top();
            pq.pop();
            
        }
        return ele;
        
    }
};
