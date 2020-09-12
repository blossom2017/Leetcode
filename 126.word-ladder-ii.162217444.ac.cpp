class Solution {
public:
    /*
    bool isvalid(string a, string b)
    {
        if(a.length()!=b.length())return false;
        int flag = 0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i]&&!flag)flag=1;
            else if(a[i]!=b[i])return false;
        }
        if(flag)return true;
        return false;
    }
    //backtracking is giving tle even with graph nodes
    void util(int &mins,vector<string> temp, string end, map<string,vector<string>> mp,vector<vector<string>> &ans,unordered_map<string,bool> visited)
    {
        //cout<<"herre"<<temp.back();
       
        if(temp.back()==end)
        {
          //  cout<<"hhhh";
            if(temp.size()<mins)mins=temp.size();
            ans.push_back(temp);
            return;
        }
        if(temp.size()>visited.size()||temp.size()>mins)return;
        for( auto it = mp[temp.back()].begin();it!=mp[temp.back()].end();it++)
        {
            if(!visited[*it])
            {
                temp.push_back(*it);
                visited[*it]=true;
                util(mins,temp,end,mp,ans,visited);
                temp.pop_back();
                visited[*it]=false;
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
         unordered_map<string,bool> visited;
        for(int i=0;i<wordList.size();i++)
        {
            visited[wordList[i]]=false;
            
            
            for(int j=i+1;j<wordList.size();j++)
            {
                if(isvalid(wordList[i],wordList[j]))
                {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if(mp.find(endWord)==mp.end())return ans;
        if(mp.find(beginWord)==mp.end())
        {
            for(int i=0;i<wordList.size();i++)
            {
                if(isvalid(beginWord,wordList[i]))
                mp[beginWord].push_back(wordList[i]);
            }
        }
        vector<string> temp;
        temp.push_back(beginWord);
        int mins = INT_MAX;
       queue<pair<vector<string>,int>> q;
            q.push({{beginWord},1});
        while(!q.empty())
        {
            pair<vector<string>,int> front = q.front();
            q.pop();
            if(front.first.back()==endWord&&mins==INT_MAX)
            {
                mins = front.second;
               // cout<<"hhh";
                ans.push_back(front.first);
                //cout<<front.first.size()<<" ";
            }
            else if(front.first.back()==endWord&&front.second==mins)
            {
                ans.push_back(front.first);
            }
            else if(front.second >= mins)continue;
            else 
            {
                vector<string> temp = front.first;
                for( auto it = mp[temp.back()].begin();it!=mp[temp.back()].end();it++)
        {
            if(find(temp.begin(),temp.end(),*it)==temp.end())
            {
                temp.push_back(*it);
                q.push({temp,front.second+1});
                temp.pop_back();
              
            }
        }
            }
        }
        cout<<mins<<" ";
       // util(mins,temp,endWord,mp,ans,visited);
       return ans;
        
        
    }
    */
      bool isvalid(string s, string t)
{
    bool flag = true;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=t[i]&&flag)flag = false;
        else if(s[i]!=t[i]&&!flag)return false;
        
    }
    return !flag;
}
    vector<vector<string> > findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string>> ans;
    unordered_set<string> wordlist;
    map<string,vector<string>> mp;
    sort(dict.begin(),dict.end());
    dict.erase(unique(dict.begin(),dict.end()),dict.end());
    for(int i=0;i<dict.size();i++)
    {
        wordlist.insert(dict[i]);
        for(int j=i+1;j<dict.size();j++)
        {
            if(isvalid(dict[i],dict[j]))
            {
                mp[dict[i]].push_back(dict[j]);
                mp[dict[j]].push_back(dict[i]);
            }
        }
    }
    wordlist.insert(end);
    if(mp.find(start)==mp.end())
    {
         for(int j=0;j<dict.size();j++)
        {
            if(isvalid(start,dict[j]))
            {
                mp[start].push_back(dict[j]);
               
            }
        }
        
    }
          if(start==end)return {{start}};
    if(mp.find(end)==mp.end())return {};
   
    int minsize=INT_MAX;
    set<string> visited;

    queue<vector<string>> q;
    q.push({start});
   // visited.insert(start);
    int level =1;
    int minlevel= INT_MAX;
         while(!q.empty())
    {
       
        vector<string> front = q.front();
        q.pop();
        if(front.size()>level)
        {
            for(auto it = visited.begin();it!=visited.end();it++)wordlist.erase(*it);
            visited.clear();
            if(front.size()>minlevel)
            {
               // cout<<"yyyy";
                break;
            }
            level = front.size();
        }
        string last =front.back();
      //  cout<<last<<endl;
        
           // cout<<"bbbb";
            for(int i=0;i<mp[last].size();i++)
            {
               // cout<<mp[last][i]<<"ggg"<<endl;
                if(wordlist.count(mp[last][i]))
                {
                    front.push_back(mp[last][i]);
                    if(mp[last][i]==end)
                    {
                 //       cout<<"herefffff";
                        ans.push_back(front);
                        minlevel= level;
                    }
                    visited.insert(mp[last][i]);
                    q.push(front);
                    front.pop_back();
                }
            }
         }
        return ans;
    }
};
