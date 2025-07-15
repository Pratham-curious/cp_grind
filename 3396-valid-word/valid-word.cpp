class Solution {
public:
    bool isValid(string word) {
        int vowel = 0, conson = 0,dig = 0;
        int n = word.size();
        for(auto it : word){
            char ch = tolower(it);
            if(ch>='0' && ch<='9'){
                dig++;
            }
            else if(ch>='a' && ch<='z'){
                if(ch == 'a' || ch =='e' || ch=='i' || ch == 'o' || ch=='u') vowel++;
                else conson++;
            }
            else return false;
        }
        if(n >2 && vowel >0 && conson > 0) return true;
        return false;
    }
};