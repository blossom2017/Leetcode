class Solution {
public:
    int countSubstrings(string s) {
        int i=0;
         int count=0;
        while(i<s.length())
        {
            //odd;
            int front = i-1;
            int end = i+1;
           count++;
            while(front>=0&&end<s.length()&&s[front]==s[end])
            {
                count++;
                front--;
                end++;
            }
            //even
             front = i;
             end=i+1;
            while(front>=0&&end<s.length()&&s[front]==s[end])
            {
                count++;
                front--;
                end++;
            }
            i++;
        }
        return count;
        
    }
};
