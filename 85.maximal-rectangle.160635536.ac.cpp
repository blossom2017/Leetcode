class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
   /*O(n3)
        
        if(r==0)return 0;
         int c = matrix[0].size();
        vector<vector<int>> dup(matrix.size(),vector<int> (matrix[0].size()));
        int flag =0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')dup[i][j]=-1;
                else if(matrix[i][j]=='1')
                {
                    flag=1;
                    dup[i][j]=0;
                }
            }
        }
        if(!flag)return 0;
       
       vector<int> temp(matrix.size());
       
        int leftmax,rightmax,upmax,downmax,cursum,maxsum;
        int glob=INT_MIN,globdown=0,globup=0,globleft=0,globright=0;
      //  cout<<"hereee";
        for(int left = 0;left<c;left++)
        {
            cout<<"yyyyy";
            for(int k=0;k<r;k++)temp[k]=0;
            for(int right =left;right<c;right++)
            {
                for(int k=0;k<r;k++)temp[k]+=dup[k][right];
                int st =0;
                int end =0;
                cursum=temp[0];
                maxsum = temp[0];
                cout<<maxsum<<" ";
                upmax = 0;
                downmax =0;
                for(int i=1;i<r;i++)
                {
                    if(temp[i]>cursum+temp[i])
                    {
                        cursum = temp[i];
                        st=i;
                        end=i;
                    }
                    else 
                    {
                        cursum+=temp[i];
                        end=i;
                    }
                    if(cursum>maxsum)
                    {
                        maxsum = cursum;
                        upmax = st;
                        downmax = end;
                    }
                    else if(cursum==maxsum)
                    {
                        if((end-st)>(downmax-upmax))
                        {
                             
                        upmax = st;
                        downmax = end;
                        }
                    }
                }
                if(maxsum>glob)
                    
                {
                    glob = maxsum;
                    globleft = left;
                    globright= right;
                    globup = upmax;
                    globdown = downmax;
                }
                else if(maxsum==glob)
                {
                    cout<<"hhhh"<<maxsum<<" ";
                    if(abs((right-left+1)*(downmax-upmax+1))>=abs((globright-globleft+1)*(globdown-globup+1)))
                    {
                    glob = maxsum;
                    globleft = left;
                    globright= right;
                    globup = upmax;
                    globdown = downmax;
                    }
                }
                }
            }
       cout<<globright<<" "<<globleft<<" "<<globup<<" "<<globdown<<" ";
        return abs(((globright - globleft+1)*(globdown - globup+1)));
      */
        //Largest area rectangle in histogram
    if(r==0)return 0;
        int c = matrix[0].size();
        vector<int> height(c+1,0);
        int mxarea =0;
        for(int i=0;i<r;i++)
        {
            height[c]=0;
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]=='0')height[j]=0;
                else height[j]++;
            }
            stack<int> st;
            for(int j=0;j<=c;j++)
            {
                if(st.empty()||height[st.top()]<=height[j])st.push(j);
                else 
                {
                    while(!st.empty()&&height[st.top()]>height[j])
                    {
                        int tp = st.top();
                        st.pop();
                        int width;
                        if(st.empty())width = -1;
                        else width = st.top();
                       int area = (j-width-1)*height[tp];
                      
                        mxarea=max(mxarea,area);
                    }
                    st.push(j);
                }
            }
        }
        return mxarea;
        }
    
};
