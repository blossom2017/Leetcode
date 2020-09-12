class Solution {
public:
    struct trienode
    {
        struct trienode * children[26];
        bool isend;
        string key;
    };
    struct trienode* getnode()
    {
        struct trienode * nn = new trienode;
       for(int i=0;i<26;i++) nn->children[i]=NULL;
        nn->isend = false;
        return nn;
    }
    void insert(struct trienode * root, string key)
    {
        struct trienode * ptr = root;
        for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            if(!ptr->children[index])ptr->children[index]=getnode();
            ptr= ptr->children[index];
        }
        ptr->isend= true;
        ptr->key = key;
    }
    string search(struct trienode * root, string str)
    {
        struct trienode * ptr = root;
        for(int i=0;i<str.length()&&ptr;i++)
        {
            
            int index = str[i]-'a';
            if(ptr->isend)return ptr->key;
            ptr = ptr->children[index];
        }
        return "";
    }
    string replaceWords(vector<string>& dict, string sentence) {
        struct trienode * root= getnode();
        for(int i=0;i<dict.size();i++)insert(root,dict[i]);
        int i=0;
        string temp;
        vector<string> v;
        while(i<sentence.length())
        {
            if(sentence[i]!=' ')temp.push_back(sentence[i++]);
            else 
            {
                if(temp!="")v.push_back(temp);
                temp.clear();
                i++;
            }
                
        }
        if(temp!="")v.push_back(temp);
        
        string ans;
        for(int i=0;i<v.size();i++)
        {
            string st =search(root,v[i]); 
            if(st!="")v[i]=st;
            ans+=v[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
        
        
        
        
    }
};
