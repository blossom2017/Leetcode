class Solution {
public:
    bool validPalindrome(string s) {
        int low =0;
        int high = s.length()-1;
        int flag =1;
        while(low<=high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
                
            }
            else 
            {
                cout<<low<<" "<<high<<" ";
                if(!flag)return false;
                
                if(s[low+1]==s[high]&&s[high-1]!=s[low])low++;
                else if(s[high-1]==s[low]&&s[low+1]!=s[high])high--;
                else if(s[low+1]==s[high]&&s[high-1]==s[low])
                {
                    if(s[low+2]==s[high-1]&&low+2<=high-1)low++;
                    else high--;
                }
                else return false;
                flag =0;
            }
        }
        return true;
        
    }
};
