class Solution {
public:
    int jump(vector<int>& nums) {
        //O(n2)giving tle for last test case
        /*
        vector<int>jumps(nums.size(),INT_MAX);
        jumps[0]=0;
        for(int i=1;i<jumps.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]+j>=i&&jumps[i]>jumps[j]+1)jumps[i]=jumps[j]+1;
            }
        }
        return jumps[nums.size()-1];
        */
        /* TLE for standard bfs
        
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            pair<int,int> front = q.front();
           // cout<<front.first<<" ";
            q.pop();
            if(front.first>=nums.size()-1)return front.second;
            int k =nums[front.first]; 
                while(k)q.push({front.first+k--,front.second+1});
        }
        */
        //BFS but not using memory
        /*
        int start =0;
        int low=0;
        int high =0;
        if(nums.size()==1)return 0;
        for(int k=0;k<nums.size();k++)
        {
            if(low>high)break;
            int far = 0;
            for(int i=low;i<=high;i++)
            {
                if(nums[i]+i>=nums.size()-1)return k+1;
                far = max(far,nums[i]+i);
            }
             low=high+1;
            high = far;
           
        }
         return -1;
        */
            
        
        int jumps = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		curFarthest = max(curFarthest, i + nums[i]);
		if (i == curEnd) {
			jumps++;
			curEnd = curFarthest;
		}
	}
	return jumps;
        
   
        
        
    }
};
