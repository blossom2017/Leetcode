class Solution {
public:
    string intToRoman(int A) {
        /*
        correct 
        vector<int> val = {1,4,5,9,10 , 40, 50 , 90 , 100, 400, 500, 900, 1000};
       vector<string> sym = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans;
        while(num>0)
        {
            for(int j=val.size()-1;j>=0;j--)
            {
                if(num>=val[j])
                {
                   // cout<<"jeee"<<" ";
                    num-=val[j];
                    ans+=sym[j];
                    break;
                }
            }
        }
        return ans;
        */
         vector<string> st = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    vector<int> val={1,4,5,9,10,40,50,90,100,400,500,900,1000};
  
    int j=val.size()-1;
    string res;
    while(A>0&&j>=0)
    {
        if(A>=val[j])
        {
           // cout<<"hhhh";
            A=A-val[j];
            res+=st[j];
            
        }
        else j--;
    }
    return res;
        
    }
};
