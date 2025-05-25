class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        int ans = 0;
        for (int i=0;i<n;i++) {
            string temp = string(1,words[i][1]);
            temp+=words[i][0];
            if (mp.find(temp) != mp.end()) {
                ans += 4;
                mp[temp]--;
                if (mp[temp] == 0)
                    mp.erase(temp);
            } else {
                mp[words[i]]++;
            }
        }
        for (auto it : mp) {
            if (it.first[0] == it.first[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};