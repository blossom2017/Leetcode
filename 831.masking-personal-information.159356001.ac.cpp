class Solution {
public:
    string maskPII(string S) {
        string ans;
        if(S.find('@')==std::string::npos)
        {
            //phone num
          //  cout<<"hhere";
            int count=0;
            string countstr;
            for(int i=0;i<S.length();i++)
            {
                if(S[i]>='0'&&S[i]<='9')
                {
                    count++;
                    countstr.push_back(S[i]);
                }
            }
                            //cout<<"hhhh";

            if(count==10)
            {
                ans+="***-***-";
                ans+=countstr.substr(countstr.length()-4,4);
            }
            else 
            {
               // cout<<"hhhh";
                ans.push_back('+');
                for(int k=0;k<count-10;k++)ans.push_back('*');
                ans.push_back('-');
                ans+="***-***-";
                ans+=countstr.substr(countstr.length()-4,4);
            }
        }
        else 
        {
            //email
            int index = S.find('@');
            char endc = S[index-1];
            ans.push_back(tolower(S[0]));
            ans+="*****";
            ans.push_back(tolower(endc));
            string y=S.substr(index,S.length()-index);
            transform(y.begin(),y.end(),y.begin(),::tolower);
            ans+=y;
        }
     return ans;   
    }
};
