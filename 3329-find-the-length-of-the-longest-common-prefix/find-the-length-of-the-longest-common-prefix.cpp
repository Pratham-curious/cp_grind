class Solution {
public:
    struct Node {
        Node* child[10] = {nullptr};
    };
    void add(string s,Node* trie){
        Node* root = trie;
        for(auto it : s){
            if(!root->child[it-'0']){
                root->child[it-'0'] = new Node;
            }
            root = root->child[it-'0'];
        }
    }
    void search(string s,Node* trie,int& ans){
        int cnt = 0;
        Node* root = trie;
        for(auto it : s){
            if(!root->child[it-'0']) break;
            root = root->child[it-'0'];
            cnt++;
        }
        ans = max(ans,cnt);
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* trie = new Node();
        for(auto it : arr1){
            string s = to_string(it);
            add(s,trie);
        }
        int ans = 0;
        for(auto it : arr2){
            string s = to_string(it);
            search(s,trie,ans);
        }
        return ans;
    }
};