class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        vector<string> ans;
        set<string> lower, check;
        vector<string> low;
        unordered_map<string,string> mp;

        int n = queries.size(), m = wordlist.size();
        for (auto it : wordlist) {
            check.insert(it);
            string temp = "";
            for (auto s : it)
                temp += tolower(s);
            lower.insert(temp);
            low.push_back(temp);
            if(mp.find(temp) == mp.end()){
                mp[temp] = it;
            }
        }
        for (int i = 0; i < n; i++) {
            bool fnd = false;
            if(check.find(queries[i]) != check.end()){
                fnd = true;
                ans.push_back(queries[i]);
            }
            if (fnd)
                continue;
            string temp = "";
            for (auto s : queries[i])
                temp += tolower(s);

            if(lower.find(temp) != lower.end()){
                fnd = true;
                ans.push_back(mp[temp]);
            }
            if (fnd)
                continue;

            for (int j = 0; j < m; j++) {
                if (low[j].size() != temp.size())
                    continue;
                int k = temp.size();
                bool complete = true;
                for (int p = 0; p < k; p++) {
                    if (low[j][p] != temp[p]) {
                        if (low[j][p] == 'a' || low[j][p] == 'e' ||
                            low[j][p] == 'o' || low[j][p] == 'i' ||
                            low[j][p] == 'u') {
                            if (temp[p] == 'a' || temp[p] == 'e' ||
                                temp[p] == 'o' || temp[p] == 'i' ||
                                temp[p] == 'u') {
                                    continue;

                            } else{
                                complete = false;
                                break;
                            }
                        } else{
                            complete = false;
                            break;
                        }
                    }
                }
                if(complete){
                    ans.push_back(wordlist[j]);
                    fnd = true;
                    break;
                }
                
            }
            if(!fnd) ans.push_back("");
        }
        return ans;
    }
};