class Solution {
public:
    string fractionToDecimal(int nr, int dr) {
        if(nr==0)return "0";
        string res;
        if((nr<0)^(dr<0))res+="-";
        long long int n = (nr<0)?(long long int)nr*-1:nr;
        long long int d = (dr<0)? (long long int)dr*-1:dr;
        long long int ing =n/d;
        res+=to_string(ing);
        long long int rem = n%d;
        if(!rem)return res;
        res+=".";
        rem*=10;
        map<long long int,long long int> mp;
        while(rem)
        {
            long long int q = rem/d;
            if(mp.find(rem)!=mp.end())
            {
                res.insert(mp[rem],1,'(');
                res+=")";
                break;
            }
            else 
            {
                 mp[rem]=res.size();
                res+=to_string(q);
               rem=(rem%d)*10;
            }
        }
        return res;
        
        
        
    }
};
