#include<string>
class Solution {
public:
 void  util(vector<string> &ans, string temp, map<int,vector<int>>mp,auto it,string s,bool endflag)
    {
   //  cout<<"here"<<it->first<<" "<<mp[it->first].size()<<" ";
        if(it==mp.end()||endflag)
        {
     //       cout<<"hhhh";
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<mp[it->first].size();i++)
        {
         //  cout<<mp[it->first][i]<<"xxxx"<<it->first<<endl;
            if(mp.find(mp[it->first][i]+1)==mp.end()&&mp[it->first][i]!=s.length()-1)continue;
            if(mp[it->first][i]==s.length()-1)endflag=true;
            util(ans, temp+s.substr(it->first,mp[it->first][i]-it->first+1)+" ",mp,mp.find(mp[it->first][i]+1),s,endflag);
            endflag=false;
           // cout<<"bacckkk";
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
      map<int,vector<int>> mp;
        //used to map index of matching with index of string in the output array 
        vector<bool> dp(s.length());
        set<string> st;
        vector<string> ans;
        int ct=0;
        for(int i=0;i<word.size();i++)st.insert(word[i]);
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s.substr(0,i+1))!=st.end())
            {
              dp[i]=true;
                mp[0].push_back(i);
            }
             
            
                for(int j=0;j<i;j++)
                {
                    if(dp[j]&&st.find(s.substr(j+1,i-j))!=st.end())
                    {
                        dp[i]=true;
                        mp[j+1].push_back(i);
                    }
                }
            
        }
      //  cout<<mp[4][0]<<endl;
        if(dp[s.length()-1]==false)return ans;
      
        util(ans,"",mp,mp.begin(),s,false);
        return ans;
        
        
    }
};
