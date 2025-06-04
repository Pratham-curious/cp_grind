class Solution {
public:
    string answerString(string word, int numFriends) {
        set<string> st;
        int n = word.size();
        string ans ="";
        if(numFriends == 1) return word;
        for(int i=0;i<n;i++){
            ans = max(ans,word.substr(i,min(n-numFriends+1,n-i)));
            
        }
        return ans;
    }
};