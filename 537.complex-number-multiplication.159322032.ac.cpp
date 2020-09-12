class Solution {
public:
    string complexNumberMultiply(string stra, string strb) {
        string a,b,c,d;
        int i=0;
        while(i<stra.size()&&stra[i]!='+')
        {
            a.push_back(stra[i++]);
        }
        i++;
        while(i<stra.size()&&stra[i]!='i')
        {
            b.push_back(stra[i++]);
        }
         int j=0;
        while(j<strb.size()&&strb[j]!='+')
        {
            c.push_back(strb[j++]);
        }
        j++;
        while(j<strb.size()&&strb[j]!='i')
        {
            d.push_back(strb[j++]);
        }
        int x,y,z,w;
    x= stoi(a);
        y= stoi(b);
        z= stoi(c);
        w= stoi(d);
        int p = x*z-y*w;
        int r = x*w+y*z;
        string ans = to_string(p)+"+"+to_string(r)+"i";
        return ans;
    }
};
