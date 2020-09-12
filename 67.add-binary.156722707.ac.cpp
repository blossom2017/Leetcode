class Solution {
public:
    string addBinary(string a, string b) {
        string sol;
        if(a.length()>b.length())
        {
            int ct = a.length()-b.length();
            reverse(b.begin(),b.end());
            while(ct--)
            {
                b.push_back('0');
            }
            reverse(b.begin(),b.end());
        }
        else if(a.length()<b.length())
        {
            int ct= b.length()-a.length();
            reverse(a.begin(),a.end());
            while(ct--)
            {
                a.push_back('0');
            }
            reverse(a.begin(),a.end());
        }
        
        int i= a.length()-1;
        int j = b.length()-1;
        int c=0;
        string r;
       cout<<a<<" "<<b<<endl;
        for(int i=b.length()-1;i>=0;i--)
        {
            if(c==0)
            {
                if(a[i]=='1'&&b[i]=='1')
                {
                   r.push_back('0');
                    c=1;
                }
                else if(a[i]=='0'&&b[i]=='0')
                {
                    r.push_back('0');
                }
                else r.push_back('1');
            }
            else if(c==1)
            {
                if(a[i]=='1'&&b[i]=='1')
                {
                   r.push_back('1');
                    c=1;
                }
                else if(a[i]=='0'&&b[i]=='0')
                {
                    r.push_back('1');
                    c=0;
                }
                else 
                {
                    r.push_back('0');c=1;
                }
            }
        }
        if(c==1)r=r+"1";
        reverse(r.begin(),r.end());
        return r;
        
    }
};
