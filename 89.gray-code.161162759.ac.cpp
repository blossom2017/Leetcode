class Solution {
public:
    int convert(string str)
    {
        int p =0;
        int sum =0;
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='1')sum+=pow(2,p);
            p++;
        }
        return sum;
    }
    void util(vector<int> &ans,string temp, int n )
    {
        if(temp.length()==n)
        {
            ans.push_back(convert(temp));
            return ;
        }
        
            util(ans,temp+"0",n);
            util(ans,temp+"1",n);
       
    }
    vector<int> grayCode(int n) {
        vector<string> temp = {"0"};
        for(int i=1;i<=n;i++)
        {
            vector<string> rp;
            
            for(int i=0;i<temp.size();i++)
            {
                if(i%2==0)
                {                
                rp.push_back(temp[i]+"0");
                rp.push_back(temp[i]+"1");
                }
                else 
                {
                    rp.push_back(temp[i]+"1");
                     rp.push_back(temp[i]+"0");
                }
            }
           
            temp = rp;
            
        }
        vector<int> ans;
        for(int i=0;i<temp.size();i++)
        {
          //  cout<<temp[i]<<" ";
            ans.push_back(convert(temp[i]));
        }
        return ans;
        
    }
};
