class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (digits[i] % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    if(i!=j)for (int k = 0; k < n; k++) {
                        if (digits[k] != 0 && i != k && k != j) {
                            st.insert(digits[k] * 100 + digits[j] * 10 +
                                        digits[i]);
                        }
                    }
                }
            }
        }
        while(!st.empty()){
            v.push_back(*st.begin());
            st.erase(st.begin());
        }
        return v;
    }
};