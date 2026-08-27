class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        map<char,int> mp;

        for(auto it : s){
            mp[it]++;
        }

        string ans = "";
        int index = -1;
        for(int i=0;i<n;i++){
            index = i;
            if(mp.find(target[i]) != mp.end()){
                ans += target[i];
                mp[target[i]]--;
                if(mp[target[i]] == 0) mp.erase(target[i]);
            }
            else {
                break;
            }   
        }
        while(index >= 0){
            if(!ans.empty() && index == ans.size()-1){
                mp[ans.back()]++;
                ans.pop_back();
            }
            auto it = mp.upper_bound(target[index]);
            if(it != mp.end()){
                char c = it->first;
                mp[c]--;
                ans += c;
                if(mp[c] == 0) mp.erase(c);
                break;
            }
            index--;
        }
        if(index < 0) return "";
        for(auto it : mp){
            int count = it.second;
            char c = it.first;
            while(count--) ans+=c;
        }
        return ans;
    }
};