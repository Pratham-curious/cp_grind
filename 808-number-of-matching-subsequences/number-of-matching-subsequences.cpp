class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> storeIdx;
        for(int i=0;i<s.size();i++){
            storeIdx[s[i]].push_back(i);
        }
        int ans = 0;
        for(int i=0;i<words.size();i++){
            int curr = -1;
            bool success = true;
            for(int j=0;j<words[i].size();j++){
                if(storeIdx.find(words[i][j]) == storeIdx.end()){ 
                    success = false;
                    break;
                }
                auto it = lower_bound(storeIdx[words[i][j]].begin(),storeIdx[words[i][j]].end(),curr)-storeIdx[words[i][j]].begin();
                if(it >= storeIdx[words[i][j]].size()){
                    success = false;
                    break;
                }
                curr = storeIdx[words[i][j]][it]+1;
            }
            if(success) ans++;
        }
        return ans;
    }
};