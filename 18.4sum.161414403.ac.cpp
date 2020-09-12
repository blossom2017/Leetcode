class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
        /*Taking lot of time 
        
       
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)mp[nums[i]+nums[j]].push_back({i,j});
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(mp.find(target-it->first)!=mp.end())
            {
               auto x=mp.find(target-it->first);
                for(int i=0;i<it->second.size();i++)
                {
                    for(int j=0;j<x->second.size();j++)
                    {
                        vector<int> temp(4);
                        temp[0]=it->second[i].first;
                        temp[1]=it->second[i].second;
                        temp[2]=x->second[j].first;
                        temp[3]=x->second[j].second;
                        if(temp[0]!=temp[2]&&temp[0]!=temp[3]&&temp[1]!=temp[2]&&temp[1]!=temp[3])
                        {
                            temp[0]=nums[temp[0]];
                            temp[1]=nums[temp[1]];
                            temp[2]=nums[temp[2]];
                            temp[3]=nums[temp[3]];
                        ans.push_back(temp);
                        }
                    }
                }
               
                mp.erase(x->first);
            }

        }
        for(int i=0;i<ans.size();i++)sort(ans[i].begin(),ans[i].end());
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
        */
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int t1 = target -nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                int t2 =t1-nums[j];
                int front = j+1;
                int back = nums.size()-1;
                while(front<back)
                {
                    if(nums[front]+nums[back]>t2)
                        back--;
                    else if(nums[front]+nums[back]<t2)
                        front++;
                    else 
                    {
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[front];
                        temp[3]=nums[back];
                        ans.push_back(temp);
                        while(front<back&&nums[front]==temp[2])++front;
                        while(front<back&&nums[back]==temp[3])--back;
                    }
                
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])j++;
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])i++;
        }
        return ans;
        
    }
};
