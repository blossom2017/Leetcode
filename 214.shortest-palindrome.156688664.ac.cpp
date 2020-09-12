class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()<=1)return s;
        string temp = "";
        string rev = s;
        reverse(rev.begin(),rev.end());
        temp=s+"$"+rev;
      //  cout<<temp<<endl;
        vector<int > lps(temp.length());
        int j=0;
        lps[0]=0;
        int i=1;
        while(i<temp.length())
        {
        //    cout<<i<<" "<<j<<" "<<endl;
            if(temp[i]==temp[j])
            {lps[i++]=j+1;
        //     cout<<"hiiii"<<" "<<endl;
             j++;
            }
            else 
            {
              //  cout<<"hhhh"<<endl;
                if(j==0)
                {lps[i++]=j;
              //   cout<<"heree"<<endl;
                }
                else j=lps[j-1];
            }
            
        }
   //     for(int i=0;i<temp.length();i++)cout<<lps[i]<<" ";
         string ans;
        
        int count = s.length()-lps[temp.length()-1];
        if(count<=0)return s;
     //   cout<<count<<lps[temp.length()-1]<<endl;
       
        int k= s.length()-1;
        while(count--)
        {
            ans.push_back(s[k--]);
        }
      //  reverse(ans.begin(),ans.end());
     
        return ans+s;
    }
};
