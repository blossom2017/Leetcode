class Solution {
public:
    vector<string> fullJustify(vector<string> &A, int B) {
if(A.size()==0)return A;
    vector<string> ans,vs;
    int i=0;
    int len = 0;
    string str;
    for(int i=0;i<A.size();i++)
    {
        if(vs.size()+len+A[i].length()<=B)
        {
            vs.push_back(A[i]);
            len += A[i].length();
        }
        else 
        {
            //last word
            if(vs.size()==1)
            {
                str=vs[0];
                str.append(B-str.length(),' ');
            
            }
            else 
            {
                int numspace = (B-len)/(vs.size()-1);
                int md = (B-len)%(vs.size()-1);
                str =vs[0];
                for(int j=1;j<vs.size();j++)
                {
                    if(j<=md)str.append(numspace+1,' ');
                    else str.append(numspace,' ');
                    str+=vs[j];
                }
              
            }
              ans.push_back(str);
                vs.clear();
                len = A[i].length();
                vs.push_back(A[i]);
        }
    }
    str = vs[0];
    for (int j = 1; j < vs.size(); ++j) str += ' ' + vs[j];
   if(B-str.length()>0) str.append(B-str.length(), ' ');
    ans.push_back(str);
   
    return ans;
    }
};
