class Solution {
public:
    struct compare{
      bool operator()(vector<int> a,vector<int> b)
      {
          return a[0]>b[0];
      }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //minheaps
        vector<int> ele;
  priority_queue<vector<int>,vector<vector<int>> , compare> pq;
        for(int i=0;i<matrix.size();i++)pq.push({matrix[i][0],i,0});
        for(int ct=0;ct<k;ct++)
        {
            ele=pq.top();
            pq.pop();
            int r =ele[1];
            int c = ele[2];
            if(c+1<matrix.size())
            pq.push({matrix[r][c+1],r,c+1});
        }
        return ele[0];
    
    }
};
