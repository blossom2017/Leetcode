class Solution {
public:
    int max(int a,int b)
    {
        if(a>=b)return a;
        else return b;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> lcs(word1.length()+1,vector<int> (word2.length()+1));
        for(int i=0;i<=word1.length();i++)
        {
            for(int j=0;j<=word2.length();j++)
            {
                if(i==0||j==0)lcs[i][j]=0;
                else if(word1[i-1]==word2[j-1])lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
       // cout<<lcs[word1.length()][word2.length()]<<" ";
        return (word1.length()+word2.length()-2*lcs[word1.length()][word2.length()]);
        
        
    }
};
