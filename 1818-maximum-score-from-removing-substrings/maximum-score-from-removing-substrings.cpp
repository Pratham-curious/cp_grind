class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        // x -> ab, y -> ba
        int a1 = 0, a2 = 0;
        stack<char> st;
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == 'b') {
                if (st.empty() || st.top() != 'a') {
                    st.push(s[i]);
                } else {
                    st.pop();
                    a1 += y;
                }
            } else
                st.push(s[i]);
        }
         if (!st.empty()) {
            stack<char> temp;
            while (!st.empty()) {
                char curr = st.top();
                st.pop();
                if(temp.empty()){
                    temp.push(curr);
                }
                else{
                    if(curr == 'b'){
                        if(temp.top() == 'a'){
                            temp.pop();
                            a1+=x;
                        }
                        else temp.push(curr);
                    }
                    else{
                        temp.push(curr);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {

            if (s[i] == 'b') {
                if (st.empty() || st.top() != 'a') {
                    st.push(s[i]);
                } else {
                    st.pop();
                    a2 += x;
                }
            } else
                st.push(s[i]);
        }
        if (!st.empty()) {
            stack<char> temp;
            while (!st.empty()) {
                char curr = st.top();
                st.pop();
                if(temp.empty()){
                    temp.push(curr);
                }
                else{
                    if(curr == 'b'){
                        if(temp.top() == 'a'){
                            temp.pop();
                            a2+=y;
                        }
                        else temp.push(curr);
                    }
                    else{
                        temp.push(curr);
                    }
                }
            }
        }

        return max(a1, a2);
    }
};