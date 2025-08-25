class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({robots[i], distance[i]});
        }
        sort(temp.begin(), temp.end());
        sort(walls.begin(), walls.end());
        vector<int> right(n, 0), left(n, 0);
        // right --->
        // left <---
        for (int i = 0; i < walls.size(); i++) {
            int idx = lower_bound(temp.begin(), temp.end(), make_pair(walls[i], INT_MIN)) - temp.begin();
            if (idx == n) {
                if(temp[n-1].second + temp[n-1].first >= walls[i])right[n - 1]++;
                continue;
            }
            if (walls[i] == temp[idx].first) {
                right[idx]++;
                left[idx]++;
            } else {
                int low = idx - 1;
                if (idx == 0) {
                    if( temp[0].first - temp[0].second <= walls[i])left[idx]++;
                } else {
                    if (temp[idx].second >= temp[idx].first - walls[i])
                        left[idx]++;
                    if (temp[low].second >= walls[i] - temp[low].first)
                        right[low]++;
                }
            }
        }
        // cout<<"RIGHT "<<endl;
        // for(auto it : right) cout<<it<<" ";
        // cout<<endl;
        // cout<<"LEFT "<<endl;
        // for(auto it : left) cout<<it<<" ";
        // cout<<endl;

        vector<int> dpright(n,0),dpleft(n,0);
        dpright[0] = right[0], dpleft[0] = left[0];
        for(int i=1;i<n;i++){
            int gap = 0;
            int curr = temp[i].first, prev = temp[i-1].first;
            int up = upper_bound(walls.begin(),walls.end(),curr)-walls.begin();
            int low = lower_bound(walls.begin(),walls.end(),prev)-walls.begin();
            gap  = up-low;
           /// cout<<"GAP : "<<gap<<" I: "<<i<<endl;
            dpright[i] = max(dpright[i-1],dpleft[i-1])+right[i];
            dpleft[i] = max(dpleft[i-1]+left[i],dpright[i-1] + min(gap,right[i-1]+left[i])-right[i-1]);
        }
        return max(dpright[n-1],dpleft[n-1]);
    }
};