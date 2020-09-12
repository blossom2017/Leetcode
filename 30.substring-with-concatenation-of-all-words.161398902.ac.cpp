class Solution {
public:
   
    vector<int> findSubstring(string s, vector<string>& words) {
     
        vector<int> ans;
        if(s.length()==0||words.size()==0)return ans;
      int len = words[0].length();
        
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)mp[words[i]]++;
       
        int n = s.length();
        int num = words.size();
        for(int i=0;i<n-len*num+1;i++)
        {
           unordered_map<string,int> seen;
            int j=0;
           // cout<<"nnn"<<endl;
            while(j<num)
            {
                string t = s.substr(i+j*len,len);
               // cout<<t<<endl;
                if(mp.find(t)!=mp.end())
                {
             //       cout<<"hhh";
                    seen[t]++;
                  //  cout<<seen[t]<<" ";
                    if(seen[t]>mp[t])break;
                }
                else 
                {
               //     cout<<"jjjj";
                    
                    break;
                
                }
                j++;
            }
            if(j==num)ans.push_back(i);
        }
        
        
        return ans;
       
    }
};
