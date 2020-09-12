class Solution {
public:
    //array erase operations take a lot of time
    
    void util(vector<int> temp, int &count,vector<int> nums, int n)
    {
        if(temp.size()==n)
        {
            count++;
            return;
        }
        if(nums.size()==0)return;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%(temp.size()+1)==0||(temp.size()+1)%nums[i]==0)
            {
                temp.push_back(nums[i]);
                vector<int> t ;
                t=nums;
                t.erase(t.begin()+i);
                util(temp,count,t,n);
                temp.pop_back();
            }
        }
    }
    //trying new method-took even more time but simple to understand
    void util2(vector<int> temp, int &count, vector<int> nums,vector<bool> used,int n)
    {
        if(temp.size()==n)
        {
            count++;
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!used[i]&&(nums[i]%(temp.size()+1)==0||(temp.size()+1)%nums[i]==0))
            {
                temp.push_back(nums[i]);
                used[i]=true;
                util2(temp,count,nums,used,n);
                used[i]=false;
                temp.pop_back();
                
            }
        }
    }
    /*
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<N; ++i) vs.push_back(i+1);
        return counts(N, vs);
    }
    int counts(int n, vector<int>& vs) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n-1]);
                ans += counts(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
    */
    //by swapping
    int util3(vector<int> & vs, int n)
    {
        if(n<=0)return 1;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(vs[i]%n==0||n%vs[i]==0)
            {
                swap(vs[i],vs[n-1]);
                ans+=util3(vs,n-1);
                swap(vs[i],vs[n-1]);
            }
        }
        return ans;
        
    }
    int countArrangement(int n) {
        vector<int> nums(n);
        vector<bool> used(n,false);
        for(int i=0;i<n;i++)nums[i]=i+1;
        int count=0;
        vector<int> temp;
       // util2(temp,count,nums,used,n);
        int ct=util3(nums,n);
        return ct;
        
        
    }
};
