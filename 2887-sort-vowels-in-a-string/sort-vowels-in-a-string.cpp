class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel;
        int n = s.size();
        for(int i=0;i<n;i++){
            char temp = tolower(s[i]);
            if(temp =='a'|| temp =='e' || temp == 'i' || temp == 'o' || temp =='u'){
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(),vowel.end());
        string ans ="";
        int j = 0;
        for(int i=0;i<n;i++){
            char temp = tolower(s[i]);
            if(temp =='a'|| temp =='e' || temp == 'i' || temp == 'o' || temp =='u'){
                ans += vowel[j];
                j++;
            }
            else ans+=s[i];
        }
        return ans;
    }
};