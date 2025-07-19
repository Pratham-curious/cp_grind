class Solution {
public:
    static bool comp(string& a, string& b) {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), comp);
        unordered_set<string> st;
        vector<string> ans;
        for (int i = 0; i < folder.size(); i++) {
            string temp = "";
            bool fnd = false;
            for (int j = 0; j < folder[i].size();) {
                temp += folder[i][j];
                j++;
                while(j < folder[i].size() && folder[i][j] != '/'){
                    temp += folder[i][j];
                    j++;
                }
                if (st.find(temp) != st.end()) {
                    fnd = true;
                    break;
                }
            }
            if (!fnd) {
                st.insert(folder[i]);
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};