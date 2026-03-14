class Solution {
public:
    void make(set<string>& st,string s,int i,int& n){
        vector<char> alp = {'a','b','c'};
        if(i == n) {
            st.insert(s);
            return;
        }
        for(auto it : alp){
            int m = s.size();
            if(m == 0){
                make(st,s+it,i+1,n);
            }
            else{
                if(it != s[m-1]) make(st,s+it,i+1,n);
            }
        }
    }
    string getHappyString(int n, int k) {
        set<string> st;
        string s="";
        make(st,s,0,n);
        if(k>st.size()) return s;
        while(k>1){
            st.erase(st.begin());
            k--;
        }
        return *st.begin();

    }
};