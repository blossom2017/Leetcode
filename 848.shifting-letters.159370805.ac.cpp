class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        shifts[shifts.size()-1]=shifts[shifts.size()-1]%26;
        for(int j=S.length()-2;j>=0;j--)
            
        {shifts[j]+=(shifts[j+1])%26;
         
        }
        
 
        for(int i=0;i<S.length()&&i<shifts.size();i++)
          
     S[i]=  (S[i] - 'a' + shifts[i]) % 26 + 'a';
            
        return S;
    }
};
