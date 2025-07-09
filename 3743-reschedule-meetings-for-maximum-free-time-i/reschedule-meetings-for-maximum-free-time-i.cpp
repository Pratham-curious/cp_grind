class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0;
        int add = 0;
        int n = startTime.size();
        for(int i=0;i<k;i++){
            add = add+endTime[i]-startTime[i];
        }
        if(k == n){
            return eventTime-add;
        }
        ans = startTime[k]-add;
        for(int i=k;i<n-1;i++){
            add = add+endTime[i]-startTime[i]-(endTime[i-k]-startTime[i-k]);
            ans = max(ans,startTime[i+1]-endTime[i-k]-add);
        }
        add = add+endTime[n-1]-startTime[n-1]-(endTime[n-1-k]-startTime[n-1-k]);
        ans = max(ans,eventTime -endTime[n-1-k] - add);
        return ans;


    }
};