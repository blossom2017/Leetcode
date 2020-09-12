class Solution {
public:
    bool ispallindrome(string str)
    {
        string rev = str;
        reverse(str.begin(),str.end());
        return rev==str;
    }
    void util(vector<vector<string>> &ans,vector<string> temp, int index,string s)
    {
        if(index==s.length())
        {
          //  cout<<"lll";
            ans.push_back(temp);
            return ;
        }
        for(int i = index;i<s.length();i++)
        {
            if(ispallindrome(s.substr(index,i-index+1)))
            {
            //    cout<<"kkk";
                temp.push_back(s.substr(index,i-index+1));
                util(ans,temp,i+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
        vector<string> temp;
        util(ans,temp,0,s);
        return ans;
    }
};
