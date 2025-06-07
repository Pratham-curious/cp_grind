class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> v(n,false);
        map<char,vector<int>> mp;
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                v[i] = true;
                int idx = mp.begin()->second.back();
                mp.begin()->second.pop_back();
                if(mp.begin()->second.empty()) mp.erase(mp.begin());
                v[idx] = true;
            }
            else mp[s[i]].push_back(i);
        }
        string ans;
        for(int i=0;i<n;i++){
            if(!v[i]) ans+=s[i];
        }
        return ans;
    }
};