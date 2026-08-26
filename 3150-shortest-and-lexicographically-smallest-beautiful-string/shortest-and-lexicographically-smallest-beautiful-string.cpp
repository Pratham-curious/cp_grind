class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        set<pair<int,string>> st;
        int left = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '1') k--;
            while((s[left] == '0' || k < 0 )&& left <= i){
                if(s[left] == '1') k++;
                left++;
            }

            if(k == 0){
                st.insert({i-left+1,s.substr(left,i-left+1)});
            }
        }

        if(st.empty()) return "";
        return (*st.begin()).second;
    }
};