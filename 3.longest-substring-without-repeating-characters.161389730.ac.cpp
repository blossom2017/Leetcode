class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        if(s.length()==0)return 0;
        int maxw = 1;
        /*
        O(n2)
        while(i<s.length())
        {
            int front = i-1;
            int back = i+1;
            set<char> st;
            st.insert(s[i]);
            int f=i,b=i;
            while(front>=0||back<s.length())
            {
                if((front>=0&&!st.count(s[front]))||(back<s.length()&&!st.count(s[back])))
                {
                    if(front>=0&&!st.count(s[front]))
                    {
                        f = front;
                        st.insert(s[front--]);
                    }
                    if(back<s.length()&&!st.count(s[back]))
                    {
                        b=back;
                        st.insert(s[back++]);
                    }
                }
                else break;
            }
           
            if(b-f+1>maxw)
            {
                // cout<<back<<" "<<front<<" ";
                maxw = b-f+1;
            }
            i++;
        }
        */
        int left=0 ,right=0;
        map<char,int> mp;
        while(right<s.length())
        {
           
            if(mp.find(s[right])==mp.end())
            {
                mp[s[right]]=right++;
            }
            else 
            {
                left = max(left,mp[s[right]]+1);
                mp[s[right]]=right++;
            }
             maxw = max(maxw,right-left);
        }
        
        return maxw;
        
    }
};
