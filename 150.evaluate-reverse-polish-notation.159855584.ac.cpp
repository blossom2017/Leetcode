class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(!(tokens[i].compare("/")==0||tokens[i].compare("+")==0||tokens[i].compare("-")==0||tokens[i].compare("*")==0))
                st.push(stoi(tokens[i]));
            else 
            {
                int ele1=st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                if(tokens[i].compare("+")==0)st.push(ele1+ele2);
                else if(tokens[i].compare("-")==0)st.push(ele2-ele1);
                else if(tokens[i].compare("*")==0)st.push(ele1*ele2);
                else st.push(ele2/ele1);
            }
        }
        return st.top();
        
    }
};
