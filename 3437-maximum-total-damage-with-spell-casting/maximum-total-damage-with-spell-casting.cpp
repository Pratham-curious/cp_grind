class Solution {
public:
    #define ll long long
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll> mp;
        int n = power.size();
        for(auto it : power) mp[it]+=it;
        ll ans = 0;
        ll secondLast = -1, last = -1,thirdLast = -1;
        for(auto it : mp){
            ll idx = it.first, val = it.second;
            if(last == -1){
                last = idx;
            }
            else if(secondLast == -1){
                if(last < idx -2){
                    mp[idx]+=mp[last];
                }
                else{
                    mp[idx] = max(mp[idx],mp[last]);
                }
                secondLast = last;
                last = idx;
            }
            else if(thirdLast == -1){
                if(secondLast == idx-2){
                     mp[idx] = max({mp[idx],mp[last],mp[secondLast]});
                }
                else if(last >= idx -2){
                    mp[idx] = max({mp[idx],mp[last],mp[idx]+mp[secondLast]});
                }
                else{
                    mp[idx] += mp[last];
                }
                thirdLast = secondLast;
                secondLast = last;
                last = idx;
            }
            else{
                if(secondLast == idx-2){
                     mp[idx] = max({mp[idx],mp[last],mp[secondLast],mp[idx]+mp[thirdLast]});
                }
                else if(last >= idx -2){
                    mp[idx] = max({mp[idx],mp[last],mp[idx]+mp[secondLast]});
                }
                else{
                    mp[idx] += mp[last];
                }
                
                thirdLast = secondLast;
                secondLast = last;
                last = idx;

            }
        }
        return mp[last];
    }
};