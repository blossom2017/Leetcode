class Solution {
public:
    bool valid(string a , string b)
{
    if(a.length()!=b.length())return false;
    bool f = false;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i]&&!f)f=true;
       else if(a[i]!=b[i]&&f)return false;
    }
       
    if(f)return true;
        return false;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string start=beginWord;
        string end= endWord;
  auto it = find(wordList.begin(),wordList.end(),endWord);
        if(it==wordList.end())return 0;
         if(find(wordList.begin(),wordList.end(),start)==wordList.end())
  {
      wordList.push_back(start);
  }
int size = wordList.size();
  
    list<int> * adj = new list <int > [size];
    vector<bool> visited(size);
    vector<int> level(size);
    for(int i=0;i<size;i++)visited[i]=false;
    for(int i=0;i<wordList.size();i++)
    {
        for(int j=i+1;j<wordList.size();j++)
        {
            if(valid(wordList[i],wordList[j]))
            {
                adj[j].push_back(i);            
                adj[i].push_back(j);
            }
            
        }
    }
        int st = find(wordList.begin(),wordList.end(),start)-wordList.begin();
    int ed = find(wordList.begin(),wordList.end(),end)-wordList.begin();
    queue<int > q;
    q.push(st);
    visited[st]=true;
    level[st]=0;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        if(front==ed)return level[ed]+1;
        for(auto it = adj[front].begin();it!=adj[front].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                level[*it]=level[front]+1;
                q.push(*it);
            }
        }
    }
    return 0;
        
   
    }
};
