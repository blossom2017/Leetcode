class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans =0;
        for(int i=0;i<words.size();i++)
        {
           int j=0,k=0;
            int f = 1;
            while(j<S.length())
            {
           char ch= S[j];
            int count =0;
            while(S[j]==ch&&j<S.length())
            {
                count++;
                j++;
            }
            int ct =0;
            while(words[i][k]==ch &&k<words[i].length())
            {
                ct++;
                k++;
            }
                if(!(ct!=0&&(ct==count||count-ct>=2||(count-ct>=1&&count>=3))))
                {
                    f=0;
                    break;
                }
            }
            if(!f)continue;
            else ans++;
            
        }
        return ans;
        
    }
};
