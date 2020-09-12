class Solution {
public:
    string convert(string s, int r) {
        int n = s.length();
     vector<vector<char>> v(r,vector<char>());
       int i = 0;
        int pat =0;
        int lastindex=r-2;
        while(i<s.length())
        {
            if(pat==0)
            {
                for(int k=0;k<r&&i<s.length();k++)v[k].push_back(s[i++]);
                pat=1;
            }
            else 
            {
                for(int k=r-2;k>=1&&i<s.length();k--)v[k].push_back(s[i++]);
                pat=0;
            }
            
            
        }
       // cout<<"heree";
        string ans;
        for(i=0;i<r;i++)
        {
            for(int j=0;j<v[i].size();j++)ans.push_back(v[i][j]);
        }
        return ans;
        
    }
};
