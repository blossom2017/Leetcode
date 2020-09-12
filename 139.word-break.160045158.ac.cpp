class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        set<string> st;
        for(int i=0;i<word.size();i++)st.insert(word[i]);
        vector<bool> dp(s.length());
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s.substr(0,i+1))!=st.end())dp[i]=true;
            else 
            {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&st.find(s.substr(j+1,i-j))!=st.end())
                {
                    dp[i]=true;
                    break;
                }
            }
            }
        }
    return dp[s.length()-1];
    }
};
