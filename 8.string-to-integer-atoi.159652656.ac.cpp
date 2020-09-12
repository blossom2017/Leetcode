class Solution {
public:
    int myAtoi(string str) {
          int i=0;
        while(str[i]==' ')i++;
        string temp;
        int sign =1;
        if(str[i]=='-')
        {
            sign =-1;
            i++;
        }
        else if(str[i]=='+')
        {
            sign=1;
            i++;
        }
        while(isdigit(str[i]))
        {
            temp.push_back(str[i]);
            i++;
        }
        if(temp.compare("")==0)return 0;
        int num=0;
        int k=0;
        while(k<temp.length())
        {
            
            if(num>(INT_MAX-(temp[k]-'0'))/10&&sign<0)return INT_MIN;
            else if(num>(INT_MAX-(temp[k]-'0'))/10&&sign>0)return INT_MAX;
            num=num*10+(temp[k++]-'0');
          
            
        }
        return sign*num;
        
        
    }
        
    
};
