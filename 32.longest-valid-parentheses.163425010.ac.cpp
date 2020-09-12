class Solution {
public:
    int longestValidParentheses(string A) {
        /*
        stack<pair<char,int >> st;
        string str= s;
	    int maxlength =0;
	    int lengthcur=0;
	    int start =-10;
	    int end=-10;
	    map<int ,int > m;
	    for(int i=0;i<str.length();i++)
	    {
	        if(str[i]=='(')
	        {
	            st.push({'(',i});
	        }
	        else if(str[i]==')')
	        {
	            if(st.empty())
	            {
	              //  cout<<"some worry";
	                continue;
	            }
	            int topindex= st.top().second;
	            st.pop();
	       //   cout<<topindex<<" "<<i<<endl;
	           m[topindex]=i;
	           maxlength=max(maxlength,lengthcur);
	        }
	    }
	    auto it = m.begin();
	    while(it!=m.end())
	    {
	        if(m.find(it->second+1)!=m.end())
	        {
	            auto x = m.find(it->second +1);
	            m[it->first]=x->second;
	        }
	        else it++;
	    }
	    
	    for(auto it=m.begin();it!=m.end();it++)
	    {
	        if(it->second-it->first+1>maxlength)maxlength=it->second-it->first+1;
	    }
        return maxlength;
        */
         stack<pair<char,int>> st;
    int maxlength=0;
    int start=-1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')st.push({A[i],i});
        else 
        {
            if(!st.empty())
            {
                pair<char,int> tp = st.top();
                st.pop();
                maxlength = max(i-tp.second+1,maxlength);
                if(st.empty())maxlength = max(maxlength,i-start);
                else if(st.top().second>start)maxlength = max(maxlength,i-st.top().second);
            }
            else start=i;
        }
    }
    return maxlength;
        
    }
};
