class Solution {
public:

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        map<char,int> mp;

        if(n == 1){
            if(s[0] > target[0]) return s;
            return "";
        }

        for(auto it : s){
            mp[it]++;
        }


        int cnt = 0;
        char odd =  '*';

        for(auto it : mp){
            if(1 & it.second){
                cnt++;
                odd = it.first;
            }
        }

        if(cnt > 1) return "";
        int j = (n/2)-1;

        vector<char> ans(n,'*');
        if(n & 1 ) {
            ans[j+1] = odd;
            mp[odd]--;
            if(mp[odd] == 0) mp.erase(odd);
        }

        int index = -1;

        for(int i=0;i<=j;i++){
            index = i;
            if(mp.find(target[i]) != mp.end()){
                ans[i] = target[i];
                ans[n-i-1] = target[i];
                mp[target[i]] -= 2;
                if(mp[target[i]] == 0) mp.erase(target[i]);
            }
            else {
                break;
            }  
        }
        bool satisfy = false;
        if(index == j && ans[j] != '*'){
            for(int i=0;i<n;i++){
                if(ans[i] == target[i]) continue;
                else if(ans[i] > target[i]){
                    satisfy = true;
                }
                break;
            }
        }

        if(satisfy){
            string temp ="";
            for(auto it : ans) temp += it;
            return temp;
        }
        else{
            while(index >= 0){
                if(ans[index] != '*'){
                    mp[ans[index]]+=2;
                    ans[index] = '*';
                    ans[n-index-1] = '*';
                }
                auto it = mp.upper_bound(target[index]);
                if(it != mp.end()){
                    char c = it->first;
                    mp[c]-=2;
                    ans[index] = c;
                    ans[n-index-1] = c;
                    if(mp[c] == 0) mp.erase(c);
                    index+=1;
                    break;
                }
                index--;
            }
        }

        if(index < 0) return "";

        for(auto it : mp){
            int count = it.second/2;
            char c = it.first;
            while(count--){
                ans[index] = c;
                ans[n-index-1] = c;
                index++;
            }
        }


        string temp ="";
        for(auto it : ans) temp += it;
        return temp;

    }
};