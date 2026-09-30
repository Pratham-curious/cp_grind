class Solution {
public:
    bool check(string& s, int m){
        int n = s.size();
        int s1 = 0 ,s2 = 0;
      //  cout<<"m is : "<<m<<endl;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                if(s1 <= s2) s1++;
                else s2++;
            }
            else{
                if(s1 >= s2) s1--;
                else s2--;
            }
       //     cout<<"s1 : "<<s1<<" , s2 : "<<s2<<endl;
            if(s1 > m || s2 > m) return false;
        }
        return true;
    }
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int low = 1, high = n;

        while (low <= high) {
            int m = low + (high - low) / 2;
            if (check(seq, m))
                high = m - 1;
            else
                low = m + 1;
        }
       // cout<<"Min size : "<<low<<endl;
        int val = low;
        vector<int> ans(n,0);
        int s1 = 0;

        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                if(s1 < val){
                    ans[i] = 1;
                    s1++;
                }
            }
            else{
                if(s1 > 0){
                    s1--;
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};