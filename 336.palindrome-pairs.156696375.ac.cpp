class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int > m;
        vector<vector<int >> ans;
        for(int i=0;i<words.size();i++)
        {
            string tempstr= words[i];
            reverse(tempstr.begin(),tempstr.end());
            m[tempstr]=i;
        }
        if(m.find("")!=m.end())
        {
            for(int i=0;i<words.size();i++)
            {
                if(ispallindrome(words[i])&&m[""]!=i)
                {
                 ans.push_back({m[""],i});
                }
            }
        }
        for(int i=0;i<words.size();i++)
        {
            vector<int > temp;
            for(int j=0;j<words[i].size();j++)
            {
                string left = words[i].substr(0,j);
                string right=words[i].substr(j,words[i].length()-j);
                if(m.find(left)!=m.end()&&ispallindrome(right)&&m[left]!=i)ans.push_back({i,m[left]});
                if(m.find(right)!=m.end()&&ispallindrome(left)&&m[right]!=i)ans.push_back({m[right],i});
            }
          
        }
        std::sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
    
    bool ispallindrome(string str)
    {
        string rev = str;
        reverse(rev.begin(),rev.end());
        if(rev.compare(str)==0)return true;
        else return false;
    }
};
