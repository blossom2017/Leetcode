class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      //  if(nums.size()==0)return{};
       int req = nums.size()/3;
        int count1=0;
        int count2 = 0;
        int a,b;
        for(int i=0;i<nums.size();i++)
        {
              if(nums[i]==a)count1++;
             else if(nums[i]==b)count2++;
            
           else if(!count1)
            {
                count1=1;
                a=nums[i];
            }
   
            else if(!count2)
            {
                count2=1;
                b=nums[i];
            }
           
           
            else 
            {
                count1--;
                count2--;
            }
        }
        int ca=0,cb=0;
        cout<<a<<" "<<b<<" ";
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==a)ca++;
        else if(nums[i]==b)cb++;
       }
        if(ca>req&&cb>req)return {a,b};
        else if(ca>req)return {a};
        else if(cb>req)return {b};
        else return {};
        
    }
};
