class Solution {
public:
    void util(string temp,int counto,int countc,vector<string>&ans )
    {
        if(counto==0&&countc==0)
        {
            ans.push_back(temp);
            return;
        }
        if(counto)util(temp+"(",counto-1,countc,ans);
        if(countc>counto)util(temp+")",counto,countc-1,ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        util(temp,n,n,ans);
        return ans;
    }
};
