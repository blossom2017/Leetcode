class Solution {
public:
    int minSteps(int n) {
       vector<int> steps(n+1,INT_MAX);
        if(n==1)return 0;
        else if(n==2)return 2;
        steps[1]=0;
        steps[2]=2;
        for(int i=3;i<=n;i++)
        {
            for(int j=i/2;j>=1;j--)
            {
                if(i%j==0&&(steps[i]>steps[j]+(i-j)/j+1))
                {
                    steps[i]=steps[j]+(i-j)/j+1;
                    break;
                }
            }
          //  cout<<steps[i]<<" ";
        }
        return steps[n];
    }
};
