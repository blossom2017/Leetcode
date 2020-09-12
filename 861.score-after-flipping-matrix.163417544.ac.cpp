class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size()==0)return 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i][0]==0)
            {
                for(int j=0;j<A[0].size();j++)A[i][j]=1-A[i][j];
            }
        }
        for(int i=1;i<A[0].size();i++)
        {
            int ct=0;
            for(int j=0;j<A.size();j++)
            {
                if(A[j][i]==0)ct++;
            }
            if(ct>A.size()/2)
            {
                for(int j=0;j<A.size();j++)A[j][i]=1-A[j][i];
            }
        }
        /*
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)cout<<A[i][j]<<" ";
            cout<<endl;
        }
        */
        int val=0;
        int q = A[0].size()-1;
        for(int k=0;k<A[0].size();k++)
        {
            for(int i=0;i<A.size();i++)
            {
                val+=(A[i][k]*pow(2,q-k));
            }
            
        }
        return val;
        
    }
};
