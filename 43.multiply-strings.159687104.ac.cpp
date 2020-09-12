class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> pos ((num1.length()+num2.length()),0);
        for(int i=num1.length()-1;i>=0;i--)
        {
            for(int j= num2.length()-1;j>=0;j--)
            {
                int mul = (num1[i]-'0')*(num2[j]-'0');
               // cout<<mul<<" ";
                pos[i+j]+=mul/10;
                pos[i+j+1]+=mul%10;
            }
        }
        for(int i=pos.size()-1;i>=0;i--)
        {
            if(pos[i]>9)
            {
                pos[i-1]+=pos[i]/10;
                pos[i]=pos[i]%10;
            }
            
        }
        string str;
       
        for(int i=0;i<pos.size();i++)
            str.push_back(pos[i]+'0');
        int i=0;
        
        while(str[i]=='0'&&i<str.length()-1)i++;
        return str.substr(i);
    }
};
