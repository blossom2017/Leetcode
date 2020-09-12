class Solution {
public:
    vector<string> split(string str)
    {
        vector<string> ans;
        int i=0;
        string temp;
        while(i<str.length())
        {
            if(str[i]!=',')temp.push_back(str[i++]);
            else 
            {
                ans.push_back(temp);
                temp.clear();
                i++;
            }
        }
        ans.push_back(temp);
        return ans;
    }
    bool isValidSerialization(string preorder) {
        vector<string> ans = split(preorder);
        stack<string> st;
    
       for(int i=0;i<ans.size();i++)
       {
          // cout<<ans[i]<<endl;
           if(ans[i]=="#"&&!st.empty()&&st.top()=="#")
           {
               while(!st.empty()&&st.top()=="#")
               {
                 //  cout<<st.top()<<"insideee ";
                   st.pop();
                   if(st.empty())
                   {
                       //cout<<"here"<<i;
                       return false;
                   }
                   st.pop();
               }
              
               
           }
           st.push(ans[i]);
          // cout<<endl;
        }
     //   cout<<"hhhh";
if(st.size()==1&&st.top()=="#")return true;
        else return false;
        
        
        
        
        
    }
};
