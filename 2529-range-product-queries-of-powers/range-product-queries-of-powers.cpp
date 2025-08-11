class Solution {
public:
    const int mod = 1e9+7;
    int expo(long a, long b){
        long res = 1;
        while(b>0){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> temp;
        for(int i=0;i<30;i++){
            if((1LL<<i) & n) temp.push_back(i);
        }
        for(int i=1;i<temp.size();i++){
            temp[i]+=temp[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0], r = queries[i][1];
            if(l >0){ 
                ans.push_back(expo(2,temp[r]-temp[l-1]));
            }
            else ans.push_back(expo(2,temp[r]));
        }
        return ans;

    }
};