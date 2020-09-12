class Solution {
public:
    void util(vector<string> &ans,int index, string S, string temp)
    {
        if(index==S.length())
        {
            ans.push_back(temp);
            return;
        }
        if(isalpha(S[index]))
        {
            temp.push_back(tolower(S[index]));
            util(ans,index+1,S,temp);
            temp.pop_back();
            temp.push_back(toupper(S[index]));
            util(ans,index+1,S,temp);
        }
        else 
        {
            temp.push_back(S[index]);
            util(ans,index+1,S,temp);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string temp;
        util(ans,0,S,temp);
        return ans;
        
    }
};
