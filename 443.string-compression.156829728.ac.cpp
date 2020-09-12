class Solution {
public:
    int compress(vector<char>& chars) {
        int pos =0;
        int start = 0;
        char ch = chars[start];
        int count =0;
        if(chars.size()==1)return 1;
        while(start<chars.size())
        {
            if(chars[start]==ch)
            {
                start++;
                count++;
            }
            else if(chars[start]!=ch)
            {
                   chars[pos++]=ch;
                ch = chars[start];
                string ct = to_string(count);
                if(count!=1)for(int i=0;i<ct.length();i++)chars[pos++]=ct[i];
                count =0;
                
             
            }
        }
           chars[pos++]=ch;
                ch = chars[start];
                string ct = to_string(count);
                if(count!=1)for(int i=0;i<ct.length();i++)chars[pos++]=ct[i];
                count =0;
        return pos;
            
    }
};
