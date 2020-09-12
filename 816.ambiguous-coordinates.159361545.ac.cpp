class Solution {
public:
    vector<string> func(string str)
    {
        cout<<"here"<<str<<" ";
        vector<string> ans;
        if(str.length()==0)return ans;
        else if(str.length()>1&&str[0]=='0'&&str[str.length()-1]=='0')return ans;
        else if(str.length()==1||str[str.length()-1]=='0')
        {
            ans.push_back(str);
            return ans;
        }
        
        else if(str.length()>1&&str[0]=='0')
        {
            ans.push_back("0."+str.substr(1));
            return ans;
        }
        else 
        {
            ans.push_back(str);
            for(int i=1;i<str.length();i++)
            {
                ans.push_back(str.substr(0,i)+"."+str.substr(i));
            }
        }
        return ans;
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        for(int i =1;i<S.length()-2;i++)
        {
            //open braces
            vector<string> A= func(S.substr(1,i));
            vector<string> B = func(S.substr(i+1,S.length()-2-i));
            for(int k=0;k<A.size();k++)
            {
                for(int j=0;j<B.size();j++)
                {
                    cout<<A[k]<<" "<<B[j];
                    ans.push_back("("+A[k]+", "+B[j]+")");
                }
            }
            
        }
        return ans;
        
    }
};
