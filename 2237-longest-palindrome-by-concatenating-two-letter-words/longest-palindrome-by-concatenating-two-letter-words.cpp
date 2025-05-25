class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int same = 0;
        map<string, int> mp;
        int ans = 0;
        for (auto it : words) {
            string temp = it;
            reverse(temp.begin(),temp.end());
            if (mp.find(temp) != mp.end()) {
                ans += 4;
                mp[temp]--;
                if (mp[temp] == 0)
                    mp.erase(temp);
            } else {
                mp[it]++;
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