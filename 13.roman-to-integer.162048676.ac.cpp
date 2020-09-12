class Solution {
public:
    int romanToInt(string A) {
         vector<string> st = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    vector<int> val={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    map<string,int> mp;
    for(int i=0;i<st.size();i++)mp[st[i]]=val[i];
    int res=0;
    int i=0;
    while(i<A.length())
    {
        if(i+1<A.length()&&(A[i]=='I'||A[i]=='X'||A[i]=='C')&&mp.find(A.substr(i,2))!=mp.end())
        {
           
            res+=mp[A.substr(i,2)];
            i+=2;
           
        }
        else 
        {
            res+=mp[A.substr(i,1)];
        i++;
        }
    }
    return res;
        
    }
};
