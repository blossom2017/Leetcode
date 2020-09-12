class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st;
        /* O(N) time and O(N) space
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='#'&&!st.empty())st.pop();
            else if(S[i]!='#')st.push(S[i]);
        }
        stack<char> st2;
          for(int i=0;i<T.length();i++)
        {
            if(T[i]=='#'&&!st2.empty())st2.pop();
            else if(T[i]!='#')st2.push(T[i]);
        }
        while(!st.empty()&&!st2.empty())
        {
            if(st.top()!=st2.top())return false;
            st.pop();
            st2.pop();
            
        }
        if(st2.empty()&&st.empty())return true;
        else return false;
        */
        //O(n2) time
        /*
        int i=0;
      int j ;
        while(i<S.length())
        {
            if(S[i]!='#')
            {
                i++;
             
            }
            else if(S[i]=='#')
            {
                int j=i;
                while(S[j]=='#')j--;
                
                if(j>=0)S[j]='#';
                i++;
            }
          
           
                
        }
        i=0;
       
        while(i<T.length())
        {
             if(T[i]!='#')
            {
                i++;
             
            }
            else if(T[i]=='#'&&j>=0)
            {
                int j=i;
                while(T[j]=='#')j--;
                
                if(j>=0)T[j]='#';
                i++;
             
            }
           
           
        }
        i=0;
        j=0;
        cout<<S<<" "<<T<<" ";
        while(i<S.length()||j<T.length())
        {
            if(i<S.length()&&j<T.length()&&S[i]!='#'&&T[j]!='#'&&S[i]!=T[j])return false;
            else if(i<S.length()&&j<T.length()&&S[i]!='#'&&T[j]!='#'&&S[i]==T[j])
            {
                i++;
                j++;
            }
            else if(i<S.length()&&S[i]!='#'&&j>=T.length())return false;
            else if(i>=S.length()&&j<T.length()&&T[j]!='#')return false;
            if(i<S.length()&&S[i]=='#')i++;
         if(j<T.length()&&T[j]=='#')j++;
            
        }
        
      return true;
      */
         int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0 && (S[i] == '#' || countA > 0)) S[i--] == '#' ? countA++ : countA--;
            while(j >= 0 && (T[j] == '#' || countB > 0)) T[j--] == '#' ? countB++ : countB--;
            if(i < 0 || j < 0) return i == j;
            if(S[i--] != T[j--]) return false;
        }
        return i == j;
        
        
    }
};
