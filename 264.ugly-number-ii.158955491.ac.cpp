class Solution {
public:
    int nthUglyNumber(int n) {
         priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
     vector<int> primes={2,3,5};
         set<long long int> s;
        
        for(int i=0;i<primes.size();i++)
        {
            pq.push((long long int)primes[i]);
            s.insert((long long int)primes[i]);
        }
      long long int top;
        if(n==1)return 1;
       
        for(int i=0;i<n-1;i++)
        {
            top= pq.top();
            pq.pop();
         
          for(int k=0;k<primes.size();k++)
          {
              if(s.find((long long int)top*primes[k])==s.end())
              {
                 // cout<<"ellle"<<top.first*primes[k]<<" ";
                  pq.push((long long int)top*primes[k]);
                  s.insert((long long int)top*primes[k]);
              }
          }
        }
        return top;
        
    }
};
