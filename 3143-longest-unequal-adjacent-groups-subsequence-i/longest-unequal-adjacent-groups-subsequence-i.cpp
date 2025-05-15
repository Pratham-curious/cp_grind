class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int last = -1;
        vector<string> ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            if(groups[i]!=last){
                ans.push_back(words[i]);
                last = groups[i];
            }
        }
        return ans;
    }
};