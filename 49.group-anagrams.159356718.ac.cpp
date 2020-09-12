class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string key = strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<string> t;
            for(int i=0;i<it->second.size();i++)t.push_back(it->second[i]);
            ans.push_back(t);
        }
        return ans;
        
    }
};
