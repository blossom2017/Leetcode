class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find(':')==string::npos)
        {
            //ipv4
            int i=0;
            vector<int> nums;
            string temp;
            while(i<IP.length())
            {
                
                if(IP[i]!='.')
                {
                    if(IP[i]<'0'||IP[i]>'9')return "Neither";
                    temp.push_back(IP[i++]);
                }
                else 
                {
                      if(temp.length()>3)return "Neither";
                 if(temp.compare("")!=0)   nums.push_back(stoi(temp));
                    else return "Neither";
                   
                    if(stoi(temp)>255)return "Neither";
                    //leading zeros
                    if(to_string(stoi(temp)).length()!=temp.length())return "Neither";
                    temp.clear();
                    i++;
                }
                    
            }
            if(temp.compare("")!=0)nums.push_back(stoi(temp));
            else return "Neither";
             if(temp.length()>3)return "Neither";
            if(to_string(stoi(temp)).length()!=temp.length())return "Neither";

            if(stoi(temp)>255)return "Neither";
            if(nums.size()!=4)return "Neither";
            return "IPv4";
        }
        else 
        {
            int i=0;
            int count=0;
            string temp;
            while(i<IP.length())
            {
               
                if(IP[i]!=':')
                {
                     if(!((IP[i]>='0'&&IP[i]<='9')||(toupper(IP[i])>='A'&&toupper(IP[i])<='F')))
                {
                     
                    return "Neither";
                }
                    temp.push_back(IP[i++]);
                }
                else 
                {
                 if(temp.compare("")!=0)   count++;
                    else return "Neither";
                    if(temp.length()>4)
                    {    
                      // cout<<"ooo"<<IP[i]; 
                    return "Neither";
                    }
                    //leading zeros
                    
                    temp.clear();
                    i++;
                }
                    
            }
            if(temp.compare("")!=0)count++;
            else return "Neither";
            if(temp.length()>4)return "Neither";
            if(count!=8)
            {
               
                return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
        
        
    }
};
