class Solution {
public:
    struct Node {
        int child[26];
        int len;
        int idx;
        
        Node() {
            fill(begin(child), end(child), -1); // Use -1 to represent nullptr
            len = INT_MAX;
            idx = -1;
        }
    };

    vector<Node> trie; // Our node pool

    void insert(const string& s, int word_idx) {
        int curr = 0; // index of the root node
        int n = s.size();

        if (trie[curr].len > n) {
            trie[curr].len = n;
            trie[curr].idx = word_idx;
        }

        // Traverse backwards to handle the suffix as a prefix
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (trie[curr].child[c] == -1) {
                trie[curr].child[c] = trie.size();
                trie.push_back(Node()); // Allocate a new node in the pool
            }
            curr = trie[curr].child[c];

            if (trie[curr].len > n) {
                trie[curr].len = n;
                trie[curr].idx = word_idx;
            }
        }
    }

    int search(const string& s) {
        int curr = 0;
        int best_idx = trie[0].idx;

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (trie[curr].child[c] == -1) break;
            
            curr = trie[curr].child[c];
            best_idx = trie[curr].idx;
        }
        return best_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.push_back(Node()); // Initialize root at index 0

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        for (const auto& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};