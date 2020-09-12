class Solution {
public:
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*
       //minheap
        priority_queue<int,vector<int>,greater<int>> pq;
     
         set<int> s;
        for(int i=0;i<primes.size();i++)
        {
            pq.push(primes[i]);
            s.insert(primes[i]);
        }
       int top;
        if(n==1)return 1;
       
        for(int i=0;i<n-1;i++)
        {
            top= pq.top();
            pq.pop();
         
          for(int k=0;k<primes.size();k++)
          {
              if(s.find(top*primes[k])==s.end())
              {
                 // cout<<"ellle"<<top.first*primes[k]<<" ";
                  pq.push(top*primes[k]);
                  s.insert(top*primes[k]);
              }
          }
        }
        return top;
        */
          vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
        }
        return ugly[n-1];
        
    }
};
