
class Solution {
public:
    void splitfunc(string str,vector<string> &tokens)
    {
        int i=0;
        string temp;
        while(i<str.length())
        {
            if(str[i]!=' ')
            {
                temp.push_back(str[i]);
                i++;
            }
            else if(str[i]==' ')
            {
                tokens.push_back(temp);
                temp.clear();
                i++;
            }
        }
        tokens.push_back(temp);
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>> mp;
        for(int i=0;i<paths.size();i++)
        {
            vector<string> tokens;
            splitfunc(paths[i],tokens);
           // cout<<tokens.size()<<" ";
            for(int j=1;j<tokens.size();j++)
            {
                int k=0;
                
                while(k<tokens[j].length())
                {
                    if(tokens[j][k]=='(')
                    {
                      
                        break;
                    }
                    k++;
                   
                }
                string dir=tokens[0]+"/"+tokens[j].substr(0,k);
                string content= tokens[j].substr(k+1,tokens[j].length()-k-2);
               // cout<<content<<" ";
                mp[content].push_back(dir);
            }
            
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            vector<string> k;
            if(it->second.size()>1)
            {
            for(int i=0;i<it->second.size();i++)k.push_back(it->second[i]);
             ans.push_back(k);
            }
           
        }
        return ans;
        
    }
};
