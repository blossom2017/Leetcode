class Solution {
public:
    
    int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> charmap = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> mp;
        for(int i=0;i<words.size();i++)
        {
            string str;
            for(int j=0;j<words[i].length();j++)
            {
                str += charmap[words[i][j]-'a'];
            }
            mp.insert(str);
        }
        return mp.size();
        
    
    }
};
