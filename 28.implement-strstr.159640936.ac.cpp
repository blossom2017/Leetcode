class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.compare("")==0)return 0;
        vector<int> lps(needle.length());
        int j = 0;
        int i=1;
        lps[0]=0;
        while(i<lps.size())
        {
            if(needle[i]==needle[j])lps[i++]=++j;
            else 
            {
                if(j==0)lps[i++]=0;
                else 
                {
                    j=lps[j-1];
                }
            }
            
        }
        i=0;
        j =0;
        while(i<haystack.length())
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==needle.length())return (i-j);
            else if(haystack[i]!=needle[j])
            {
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return -1;
        
    }
};
