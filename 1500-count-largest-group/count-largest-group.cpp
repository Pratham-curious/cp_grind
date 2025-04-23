class Solution {
public:

    int countLargestGroup(int n) {
        vector<int> v(1e4+1,0);
        for(int i=1;i<=n;i++){
            int temp = i, cnt = 0;
            while(temp>0){
                cnt += temp%10;
                temp/=10;
            }
            v[cnt]++;
        }
        int ans = 0, maxi = 0;
        for(auto it : v){
            if(it > maxi){
                maxi = it;
                ans = 1;
            }
            else if(it == maxi) ans++;
        }
        return ans;
    }
};