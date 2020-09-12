class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)return 0;
        int j = s.length()-1;
        string temp;
        while(s[j]==' '&&j>=0)j--;
        while(s[j]!=' '&&j>=0)
        {
            temp.push_back(s[j]);
            j--;
        }
        return temp.length();
        
    }
};
