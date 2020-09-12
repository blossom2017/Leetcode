class Solution {
public:
  void util(vector<string> & ans, int index, string temp, string digits,unordered_map<int,string> m)
    {
        
        if(index==digits.length())
        {
            if(temp.length()>0)ans.push_back(temp);
            return ;
        }
        for(int i=0;i<m[digits[index]-'0'].length();i++)
        {
            temp.push_back(m[digits[index]-'0'][i]);
            util(ans,index+1,temp,digits,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string> ans;
        string temp;
        util(ans,0,temp,digits,m);
        return ans;
        
    }
};
