class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string sentence = text;
        istringstream ss(sentence);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }
        unordered_set<char> st;
        for(auto it : brokenLetters) st.insert(it);

        int ans = 0;
        for(auto it : words){
            bool err = false;
            for(auto ch : it){
                if(st.find(ch) != st.end()){
                    err = true;
                    break;
                }
            }
            if(!err) ans++;
        }
        return ans;
    }
};