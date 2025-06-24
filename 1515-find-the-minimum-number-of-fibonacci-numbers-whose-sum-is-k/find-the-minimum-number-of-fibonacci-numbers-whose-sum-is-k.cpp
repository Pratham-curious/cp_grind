class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> v = {1,1};
        for(int i=0;i<k;i++){
            int n = v.size();
            int last = v[n-1]+v[n-2];
            if(last > k ) break;
            v.push_back(last);
        }
        int ans = 0;
        int m = v.size();
        while(k > 0){
            auto it = upper_bound(v.begin(),v.end(),k)-v.begin();
            if(it == 0) continue;
            it--;
            ans++;
            k-=v[it];
        }
        return ans;
    }
};