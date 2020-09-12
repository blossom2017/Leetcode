class Solution {
public:
   //TLE
    /*
    void util(int &count,string &ans,vector<int> temp,int index,int k,int target,vector<int> nums)
    {
       // for(int i=0;i<temp.size();i++)cout<<temp[i];
     //   cout<<"heree"<<index<<endl;
       
        if(index==target||nums.size()==0)
        {
            count++;
            if(count==k)
            {
                for(int i=0;i<temp.size();i++)ans.push_back(temp[i]+'0');
            }
            return ;
        }
        if(index>target||count>k)return;
        
        for(int i=0;i<nums.size();i++)
        {
             temp.push_back(nums[i]);
            vector<int> t;
            t=nums;
            t.erase(t.begin()+i);
            util(count,ans,temp,index+1,k,target,t);
        
            temp.pop_back();
        }
    }
    */
    
    string getPermutation(int n, int k) {
        vector<int> fact(n+1);
        fact[0]=1;        
        for(int i=1;i<n;i++)fact[i]=fact[i-1]*i;
        string ans;
        string nums = "123456789";
        k--;
        for(int i=n;i>=1;i--)
        {
            int r = k/fact[i-1];
            k%=fact[i-1];
            ans.push_back(nums[r]);
            nums.erase(nums.begin()+r);
        }
        return ans;
        
        
    }
};
