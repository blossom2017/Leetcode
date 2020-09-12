class Solution {
public:
    struct compare
    {
      bool operator()(vector<int> a,vector<int> b)
      {
          return a[0]>b[0];
      }
    };
    int min(int a ,int b)
    {
        if(a<b)return a;
        else return b;
    }
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
        vector<pair<int,int>> ans;
         if(nums1.size()==0||nums2.size()==0)return ans;
        //minheap
        priority_queue<vector<int>,vector<vector<int>>, compare> pq;
        set<pair<int,int>> s;
        vector<int> v(3);
        v[0]=nums1[0]+nums2[0];
        v[1]=0;
        v[2]=0;
        pq.push(v);
        s.insert({0,0});
        
        for(int i=0;i<min(k,nums1.size()*nums2.size());i++)
        {
            vector<int > top= pq.top();
            pq.pop();
            ans.push_back({nums1[top[1]],nums2[top[2]]});
            int i1=top[1];
            int i2= top[2];
           // cout<<i1<<" "<<i2<<" "<<endl;
            if(i1+1<nums1.size()&&s.find({i1+1,i2})==s.end())
            {
                pq.push({nums1[i1+1]+nums2[i2],i1+1,i2});
                s.insert({i1+1,i2});
            }
            if(i2+1<nums2.size()&&s.find({i1,i2+1})==s.end())
            {
                pq.push({nums1[i1]+nums2[i2+1],i1,i2+1});
                s.insert({i1,i2+1});
            }
            
        }
        return ans;
        
    }
};
