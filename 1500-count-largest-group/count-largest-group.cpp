class Solution {
public:

    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            int temp = i, cnt = 0;
            while(temp>0){
                cnt += temp%10;
                temp/=10;
            }
            mp[cnt]++;
        }
        int ans = 0, maxi = 0;
        for(auto it : mp){
            if(it.second > maxi){
                maxi = it.second;
                ans = 1;
            }
            else if(it.second == maxi) ans++;
        }
        return ans;
    }
};