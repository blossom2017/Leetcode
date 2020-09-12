class Solution {
public:
    string longestPalindrome(string s) {
        
        int i=0;
        string ans;
        int maxlength=0;
        while(i<s.length())
        {
            //odd length
            int start = i;
            int end = i;
            while(start>=0&&end<s.length()&&s[start]==s[end])
            {
                start--;
                end++;
            }
            start++;
            end--;
            if(end-start+1>maxlength)
            {
                maxlength=end-start+1;
                ans= s.substr(start,end-start+1);
            }
            //even
             start = i;
             end = i+1;
             while(start>=0&&end<s.length()&&s[start]==s[end])
            {
                start--;
                end++;
            }
            start++;
            end--;
            if(end-start+1>maxlength)
            {
                maxlength=end-start+1;
                ans= s.substr(start,end-start+1);
            }
            i++;
        }
        return ans;
        
    }
};
