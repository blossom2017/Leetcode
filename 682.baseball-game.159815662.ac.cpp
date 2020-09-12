class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum=0;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i].compare("C")==0)
            {
               // cout<<"v ";
             st.pop();
                
            }
            else if(ops[i].compare("D")==0)
            {
             //   cout<<" r";
            st.push(2*st.top());
                
            }
            else if(ops[i].compare("+")==0)
            {
               // cout<<"hhhere ";
                int tp1 =0,tp2=0;
                
              
               tp1 = st.top();
                st.pop();
          
                    tp2 =st.top();
                    st.pop();
                
                st.push(tp2);
                st.push(tp1);
                st.push(tp1+tp2);
               // cout<<tp1+tp2<<"pppush "<<tp1<<" "<<tp2<<endl;
            }
            else
            {
              //  cout<<"lll ";
                st.push(stoi(ops[i]));
            }
           // cout<<st.top()<<" ";
        }
        while(!st.empty())
        {
         sum+=st.top();
            st.pop();
        }
        return sum;
        
    }
};
