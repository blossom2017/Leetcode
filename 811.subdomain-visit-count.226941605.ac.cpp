class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        string str;
        unordered_map<string,int> mp;
        for(int i=0;i< cpdomains.size();i++)
        {
            string str;
            int count = 0;
            int k =0;
            while(k<cpdomains[i].size()&&cpdomains[i][k]>='0'&&cpdomains[i][k]<='9')count= count*10 + (cpdomains[i][k++]-'0');
            for(int k= cpdomains[i].size()-1;k>=0  && cpdomains[i][k]!= ' ' ;k--)
            {
                 cout<<"heree";
                if(cpdomains[i][k] != '.')
                str.push_back(cpdomains[i][k]);
                else
                {
                    cout<<"heree";
                    reverse(str.begin(),str.end());
                    if(mp.find(str)==mp.end())
                    {
                        mp[str]=count;
                    }
                    else mp[str]+= count;
                   
                    reverse(str.begin(),str.end());
                     str.push_back('.');
                }
                
            }
            reverse(str.begin(),str.end());
             if(mp.find(str)==mp.end())
                    {
                        mp[str]=count;
                    }
                    else mp[str]+= count;
                   
            
        }
        vector<string> ans;
        for( auto it = mp.begin(); it != mp.end() ; it++)
        {
            string temp = to_string(it->second);
            ans.push_back(temp+" "+it->first);
        }
        return ans;
        
    }
};
