class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch-'a']++;
            if(freq[ch-'a']==2){
                return ch ;
            }
        }
        return -1 ;
    }
};