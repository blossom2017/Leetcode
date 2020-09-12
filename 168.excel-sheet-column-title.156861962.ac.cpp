class Solution {
public:
    string convertToTitle(int n) {
        string str;
        
        while(n>0)
        {
         
            int x = n%26;
            x=(x-1+26)%26;
            str.push_back('A'+x);
               cout<<n<<" "<<x<<endl;
            n=(n-1)/26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
