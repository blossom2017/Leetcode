class Solution {
public:
    int nextGreaterElement(int n) {
        string str;
        if(n==INT_MAX)return -1;
        while(n>0)
        {
            int r=n%10;
            str.push_back(r+'0');
            n=n/10;
        }
        string dec = str;
        sort(dec.begin(),dec.end());
       
        if(dec==str)return -1;
        reverse(str.begin(),str.end());
        
       
        int f=0;
        for(int j=str.length()-1;j>=1;j--)
        {
         if(str[j-1]<str[j])
         {
             f=1;
             int small =j;
             for(int k= j;k<str.length();k++)
             {
                 if(str[k]>str[j-1]&&str[k]<str[small])
             {
             small= k;
                 
             }
             }
              char temp = str[small];
                     str[small]= str[j-1];
                     str[j-1]= temp;
             std::sort(str.begin()+j,str.end());
             try
             {
                 int x= stoi(str);
                 return x;
             }
             catch(std::out_of_range& e)
             {
                 return -1;
             }
         }
        }
           
  return -1;
        
    }
};
